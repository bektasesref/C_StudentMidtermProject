/*int GetLengthOfCharArray(char* ptr)
{
	int size = sizeof(ptr)/sizeof(char*);
	return size;
}*/

#define atoa(x) #x // function define for int to string casting

int CalculateStudentCourseGrade(grades_t grade)
{
	double calculatedGrade = 0.0;
	calculatedGrade += grade.final*FINALWEIGHT/100;
	calculatedGrade += grade.midterm*MIDTERMWEIGHT/100;
	calculatedGrade += grade.quiz*QUIZWEIGHT/100;
	calculatedGrade += grade.homework*HOMEWORKWEIGHT/100;
	return calculatedGrade;
}
double CalculateStudentGPA(student_t student)
{
	double calculatedGPA = 0;
	int sizeOfCourseArray = COURSESREGISTERED;
	int c = 0;
	for (c = 0; c < sizeOfCourseArray; c++) // Loop for every Course that Registered
	{
			courseReg_t courseRegisteredStruct;
			courseRegisteredStruct = student.courses[c];
				grades_t gradeStruct= courseRegisteredStruct.grades;
				calculatedGPA += CalculateStudentCourseGrade(gradeStruct);	
	/*	if (student.courses[c] != NULL) // Iteration count will equal to COURSESREGISTERED, therefore we need to check the nullability
		{
		
		}*/
	}
	calculatedGPA /= sizeOfCourseArray;
	calculatedGPA /= 25;
	return calculatedGPA;
}
