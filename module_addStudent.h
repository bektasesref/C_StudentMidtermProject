student_t AddStudent()
{
	name_t studentNameStruct;
	
	// Student Name
	INPUT_NAME:;
	char studentNameChar[NAMELENGTH];
   	printf("\nEnter Student Name:");
   	scanf("%s", studentNameChar);
	if (strlen(studentNameChar) > NAMELENGTH)
	{
	   	printf("\nStudent Name Length Can Not Exceed %d, Type Again\n", NAMELENGTH);
		goto INPUT_NAME;
	}
	*studentNameStruct.name= studentNameChar;
	printf("\nStudent Name: %s\n",studentNameChar);
	
	// Student Surname
	INPUT_SURNAME:;
	char studentSurname[NAMELENGTH];
   	printf("\nEnter Student Surname:");
   	scanf("%s", studentSurname);
	if (strlen(studentSurname) > NAMELENGTH)
	{
	   	printf("\nStudent Surname Length Can Not Exceed %d, Type Again\n", NAMELENGTH);
		goto INPUT_SURNAME;
	}
	*studentNameStruct.surname= studentSurname;
	printf("\nStudent Surname: %s\n",studentSurname);
	
	
	student_t studentInfoStruct;
	
	// Student No
	INPUT_NO:;
	char studentNo[STUDENTNUMBERLENGTH];
   	printf("\nEnter Student No:");
   	scanf("%s", studentNo);
	if (strlen(studentNo) > STUDENTNUMBERLENGTH)
	{
	   	printf("\nStudent No Length Can Not Exceed %d, Type Again\n", STUDENTNUMBERLENGTH);
		goto INPUT_NO;
	}
	*studentInfoStruct.stNo= studentNo;
	printf("\nStudent No: %s\n",studentNo);
	
	studentInfoStruct.studentName = studentNameStruct;
	
	
	// Student GPA
	INPUT_GPA:;
	double studentGPA = 0;
   	printf("\nEnter Student GPA:");
   	scanf("%lf", &studentGPA);
   	if (studentGPA < 0.00 || studentGPA > 4.00)
   	{
	   	printf("\nStudent GPA Must Be Between %s - %s, Type Again\n", "0.00", "4.00");
		goto INPUT_GPA;
	}
	studentInfoStruct.gpa= studentGPA;
	printf("\nStudent GPA: %5.2lf\n",studentGPA); // 5.2 is for trimming extra digits. It converts 15.2000000 to 15.2
	
	
	// Student Courses
	INPUT_COURSE_REGISTER:;
	int courseCountRegistered = 0;
	int courseCountToRegister;
	printf("\n\nMake a course count to register between 1 and %d \n", COURSESREGISTERED);
	scanf("%d", &courseCountToRegister);
	if (courseCountToRegister < 1 || courseCountToRegister > COURSESREGISTERED)
	{
		printf("%d is not between 1 and %d\n",courseCountToRegister, COURSESREGISTERED);
		goto INPUT_COURSE_REGISTER;
	}

	printf("\nSelected Course Count to Register: %d\n",courseCountToRegister);
	
	courseReg_t courseStruct[COURSESREGISTERED];
	
	for(courseCountRegistered = 0; courseCountRegistered < courseCountToRegister; courseCountRegistered++)
	{ // Now it's time to create courseReg_t for n count (course details)
	
		courseReg_t courseRegStruct;
		
			// Course Name
			INPUT_COURSE_NAME:;
			char courseNameChar[COURSENAMELENGTH];
		   	printf("\nEnter Course Name:");
		   	scanf("%s", courseNameChar);
			if (strlen(courseNameChar) > COURSENAMELENGTH)
			{
			   	printf("\Course Name Length Can Not Exceed %d, Type Again\n", COURSENAMELENGTH);
				goto INPUT_COURSE_NAME;
			}
			*courseRegStruct.courseName= courseNameChar;
			printf("\Course Name: %s\n",courseNameChar);
			
			// Course Code
			INPUT_COURSE_CODE:;
			char courseCodeChar[COURSECODELENGTH];
		   	printf("\nEnter Course Code:");
		   	scanf("%s", courseCodeChar);
			if (strlen(courseCodeChar) > COURSECODELENGTH)
			{
			   	printf("\Course Code Length Can Not Exceed %d, Type Again\n", COURSECODELENGTH);
				goto INPUT_COURSE_CODE;
			}
			*courseRegStruct.courseCode= courseCodeChar;
			printf("\Course Code: %s\n",courseCodeChar);
			
			// Letter Grade
			INPUT_COURSE_LETTER_GRADE:;
			char courseLetterGradeChar[COURSELETTERGRADELENGTH];
		   	printf("\nEnter Letter Grade:");
		   	scanf("%s", courseLetterGradeChar);
			if (strlen(courseLetterGradeChar) > COURSELETTERGRADELENGTH)
			{
			   	printf("\Letter Grade Length Can Not Exceed %d, Type Again\n", COURSELETTERGRADELENGTH);
				goto INPUT_COURSE_LETTER_GRADE;
			}
			*courseRegStruct.courseCode= courseLetterGradeChar;
			printf("\Letter Grade: %s\n",courseLetterGradeChar);
			
			// Numeric Grade
			INPUT_COURSE_NUMERIC_GRADE:;
			double courseNumericGradeChar;
		   	printf("\nEnter Numeric Grade Between 0 and 100:");
		   	scanf("%lf", &courseNumericGradeChar);
			if (courseNumericGradeChar < 0 || courseNumericGradeChar > 100)
			{
			   	printf("\Numeric Grade Is Not Between 1 and 100, Type Again\n");
				goto INPUT_COURSE_NUMERIC_GRADE;
			}
			courseRegStruct.numericGrade= courseNumericGradeChar;
			printf("\Numeric Grade: %5.2lf\n",courseNumericGradeChar);
			
			// Grades
			grades_t gradeStruct;
				{
					// To take grades of midterm, final, quiz and homework as double
					
					// Midterm Grade
					INPUT_GRADE_MIDTERM:;
					double gradeMidtermChar;
				   	printf("\nEnter Midterm Grade Between 0 and 100:");
				   	scanf("%lf", &gradeMidtermChar);
					if (gradeMidtermChar < 0 || gradeMidtermChar > 100)
					{
					   	printf("\Midterm Grade Is Not Between 1 and 100, Type Again\n");
						goto INPUT_GRADE_MIDTERM;
					}
					gradeStruct.midterm= gradeMidtermChar;
					printf("\Midterm Grade: %5.2lf\n",gradeMidtermChar);
					
					// Final Grade
					INPUT_GRADE_FINAL:;
					double gradeFinalChar;
				   	printf("\nEnter Final Grade Between 0 and 100:");
				   	scanf("%lf", &gradeFinalChar);
					if (gradeFinalChar < 0 || gradeFinalChar > 100)
					{
					   	printf("\Final Grade Is Not Between 1 and 100, Type Again\n");
						goto INPUT_GRADE_FINAL;
					}
					gradeStruct.final= gradeFinalChar;
					printf("\Final Grade: %5.2lf\n",gradeFinalChar);
					
					// Quiz Grade
					INPUT_GRADE_QUIZ:;
					double gradeQuizChar;
				   	printf("\nEnter Quiz Grade Between 0 and 100:");
				   	scanf("%lf", &gradeQuizChar);
					if (gradeQuizChar < 0 || gradeQuizChar > 100)
					{
					   	printf("\Quiz Grade Is Not Between 1 and 100, Type Again\n");
						goto INPUT_GRADE_QUIZ;
					}
					gradeStruct.quiz= gradeQuizChar;
					printf("\Quiz Grade: %5.2lf\n",gradeQuizChar);
					
					// Homework Grade
					INPUT_GRADE_HOMEWORK:;
					double gradeHomeworkChar;
				   	printf("\nEnter Homework Grade Between 0 and 100:");
				   	scanf("%lf", &gradeHomeworkChar);
					if (gradeHomeworkChar < 0 || gradeHomeworkChar > 100)
					{
					   	printf("\Homework Grade Is Not Between 1 and 100, Type Again\n");
						goto INPUT_GRADE_HOMEWORK;
					}
					gradeStruct.homework= gradeHomeworkChar;
					printf("\Homework Grade: %5.2lf\n",gradeHomeworkChar);
				}
			courseRegStruct.grades= gradeStruct;
		
		courseStruct[courseCountRegistered] = courseRegStruct; // assign scoped struct to array end of all course details has been set
		
	studentInfoStruct.courses[courseCountRegistered] = *courseStruct;
	}
	
	WriteToDatabaseStudentInfo(studentInfoStruct);
	
	return studentInfoStruct;
}
