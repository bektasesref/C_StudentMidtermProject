#include "module_addStudent.h"
#include "module_addCourse.h"

char* welcomeScreenHeadlines[] = {"Add Student","Add Course","Calculate Student Course Grade","Calculate Student GPA","Display Student Info","Display Course Info","Print Class","Calculate Course Average"}; // To make easy to print headlines

int PrintWelcomeScreenSelections()
{
	int i = 0;
	int sizeOfCharArray = sizeof(welcomeScreenHeadlines)/sizeof(char*);
	for (i = 0; i < sizeOfCharArray; i++) 
  		printf("%d) %s %c",i+1, welcomeScreenHeadlines[i],'\n');
}

int GetSelection()
{
	GET_SELECTION:;
	int selection;
	int sizeOfCharArray = sizeof(welcomeScreenHeadlines)/sizeof(char*);
	printf("\n\nMake a selection between 1 and %d \n", sizeOfCharArray);
	scanf("%d", &selection);
	if (selection < 1 || selection > sizeOfCharArray)
	{
		printf("%d is not between 1 and %d\n",selection, sizeOfCharArray);
		goto GET_SELECTION;
	}
	printf("\nSelected: %d \n",selection);
	return selection;
}

int SetSelection(int selection)
{
	// 3 Test, data will be deserialized from DB
	grades_t *gradeStruct = malloc(sizeof(grades_t));
	gradeStruct -> midterm = 100;
	gradeStruct -> final = 100;
	gradeStruct -> quiz = 100;
	gradeStruct -> homework = 100;
	
	int studentCourseGradeAverage = 0;
	// ---
	
	
	// 4 Test, data will *be deserialized from DB
	student_t studentStruct4;
	courseReg_t courseRegisteredStruct4;
	grades_t gradesStructGPA4;
	
	
	gradesStructGPA4.midterm = 100;
	gradesStructGPA4.final = 100;
	gradesStructGPA4.quiz = 100;
	gradesStructGPA4.homework = 100;
	courseRegisteredStruct4.grades = gradesStructGPA4;
	*courseRegisteredStruct4.courseCode = "TR";
	*courseRegisteredStruct4.courseName = "Turkey";
	studentStruct4.courses[0] = courseRegisteredStruct4;
	
	double studentGPA = 0.0;
	// ---
	
	// 5 Test, data will *be deserialized from DB
	student_t studentStruct5;
	//printf("asd: %5.2lf", studentStruct5.gpa);
	/*
	student_t *studentStruct5 = malloc(sizeof(student_t));
	name_t *studentNameStruct =  malloc(sizeof(name_t));
	courseReg_t *courseRegisteredStruct5 =  malloc(sizeof(courseReg_t));
	grades_t *gradesStructGPA5 =  malloc(sizeof(grades_t));
	
	studentNameStruct -> name = "Eşref";
	studentNameStruct -> surname = "Bektaş";
	
	studentStruct5 -> stNo = "3111999";
	
	studentStruct5 -> gpa = 4.00;
	studentStruct5 -> studentName = *studentNameStruct;
	
	gradesStructGPA5 -> midterm = 5;
	gradesStructGPA5 -> final = 10;
	gradesStructGPA5 -> quiz = 15;
	gradesStructGPA5 -> homework = 20;
	courseRegisteredStruct5 -> grades = *gradesStructGPA5;
	
	courseRegisteredStruct5 -> numericGrade = 100;
	courseRegisteredStruct5 -> letterGrade = "AA";
	courseRegisteredStruct5 -> courseName = "Internet Programciligi";
	courseRegisteredStruct5 -> courseCode = "NETPROG";
	
	studentStruct5 -> courses[0] = courseRegisteredStruct5;
	studentStruct5 -> courses[1] = courseRegisteredStruct5;
	*/
	int sizeOfCourseArray = sizeof(studentStruct5.courses)/sizeof(courseReg_t*);
	int step5CourseIterator = 0;
	
	// ---
	// 6 Test, data will *be deserialized from DB
	
	// ---
	
	switch(selection)
	{
		case 1: // Add Student
			AddStudent();
			//printf("Test After: %s", studentInfoStruct->studentName.name);
			//WriteToDatabaseStudentInfo(studentInfoStruct);
		break;
		case 2: // Add Course
			 AddCourse();
		break;
		case 3: // Calculate Student Course Grade
		    //studentCourseGradeAverage = CalculateStudentCourseGrade(gradeStruct);
			printf("\nStudent Course Grade: %d", studentCourseGradeAverage);
		break;
		case 4: // Calculate Student GPA
		    studentGPA = CalculateStudentGPA(studentStruct4);
			printf("\nStudent GPA: %5.2lf", studentGPA);
		break;
		case 5: // Display Student Info
			studentStruct5 = ReadFromDatabaseStudentInfo();
			printf("\nName: %s", studentStruct5.studentName.name);
			printf("\nSurname: %s", studentStruct5.studentName.surname);
			printf("\nGPA: %5.2lf", studentStruct5.gpa);
			printf("\nNo: %s", studentStruct5.stNo);
			printf("\nRegistered Course Count: %d", sizeOfCourseArray);
			if (sizeOfCourseArray > 0)
			{
				for (step5CourseIterator = 0; step5CourseIterator < sizeOfCourseArray; step5CourseIterator++)
				{
						courseReg_t courseRegisteredStructToRead;
						courseRegisteredStructToRead = studentStruct5.courses[step5CourseIterator];
						
						printf("\n----------");
						printf("\nCourse Name: %s", courseRegisteredStructToRead.courseName);
						printf("\nCourse Code: %s", courseRegisteredStructToRead.courseCode);
						printf("\nNumeric Grade: %5.2lf", courseRegisteredStructToRead.numericGrade);
						printf("\nLetter Grade: %s", courseRegisteredStructToRead.letterGrade);
						
						grades_t gradeStruct;
						gradeStruct = courseRegisteredStructToRead.grades;
						
						printf("\nHomework: %5.2lf", gradeStruct.homework);
						printf("\nQuiz: %5.2lf", gradeStruct.quiz);
						printf("\nMidterm: %5.2lf", gradeStruct.midterm);
						printf("\nFinal: %5.2lf", gradeStruct.final);
						printf("\nCourse Grade: %d", CalculateStudentCourseGrade(gradeStruct));
				}
			}
		break;
		case 6: // Display Course Info
		ReadFromDatabaseStudentInfo();
		break;
	}
}
