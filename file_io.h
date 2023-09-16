#define DATA_SIZE 4096

char* DBFileName = "Database.db";
 
int WriteToDatabaseStudentInfo(student_t studentInfo)
{
    FILE *filePointer;
 
    filePointer = fopen(DBFileName, "w");
 	fwrite (&studentInfo, sizeof(student_t), 1, filePointer);
    //fprintf(filePointer, "%s",structToWriteFile.studentName.name);
    
    fclose(filePointer);
    
    printf ("\nWrited Student GPA To File: %5.2lf", studentInfo.gpa);
    printf ("\nWrited Student No To File: %s", studentInfo.stNo);
    printf ("\nWrited Student Name To File: %s", studentInfo.studentName.name);
    printf ("\nWrited Student Surname To File: %s", studentInfo.studentName.surname);
    return 0;
}

student_t ReadFromDatabaseStudentInfo()
{
	student_t studentInfo;

    FILE *filePointer;
 
    filePointer = fopen(DBFileName, "r");
    
    while(fread(&studentInfo, sizeof(student_t), 1, filePointer)) 
    {
    	printf ("\nRead Student GPA From File: %5.2lf", studentInfo.gpa);
    	printf ("\nRead Student No From File: %s", studentInfo.stNo); 
    	printf ("\nRead Student Name From File: %s", studentInfo.studentName.name);
    	printf ("\nRead Student Surname From File: %s", studentInfo.studentName.surname);
	}
    
	fclose(filePointer);
    
	printf("\n---End of File Read---");
	
	printf("\nName: %s", studentInfo.studentName.name);
	return studentInfo;
}

int WriteToDatabase(const char * textToWrite)
{
    char data[DATA_SIZE];

    FILE *filePointer;
 
    filePointer = fopen(DBFileName, "a"); // A for append

    fputs(textToWrite, filePointer);

    fclose(filePointer);

    return 0;
}

int CreateDatabase()
{
    char data[DATA_SIZE];

    FILE *filePointer;
 
    filePointer = fopen(DBFileName, "w");// W for write
    
    fputs(data, filePointer);

    fclose(filePointer);

	printf("Database Created!\n");
	
    return 0;
}

char ReadFromDatabase()
{
    char str[MAXCHAR];
    FILE *filePointer;
    if (filePointer = fopen(DBFileName, "r")) // R for Read
	{
		fscanf(filePointer,"%s", &str);
        fclose(filePointer);
    }
    return str;
}

int CheckIfDatabaseExists()
{
    FILE *filePointer;
    if (filePointer = fopen(DBFileName, "r"))
	{
        fclose(filePointer);
        return 1;
    }
    return 0;
}
