courses_t AddCourse()
{
	courses_t courseInfoStruct;
	
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
	*courseInfoStruct.courseName= courseNameChar;
	printf("\Course Name: %s\n",courseNameChar);
	
	// Course Code
	INPUT_COURSE_CODE:;
	char courseCodeChar[COURSECODELENGTH];
   	printf("\nEnter Course Code:");
   	scanf("%s", courseCodeChar);
	if (strlen(courseCodeChar) > COURSECODELENGTH)
	{
	   	printf("\nCourse Code Length Can Not Exceed %d, Type Again\n", COURSECODELENGTH);
		goto INPUT_COURSE_CODE;
	}
	*courseInfoStruct.courseCode= courseCodeChar;
	printf("\Course Code: %s\n",courseCodeChar);
	
	// Course Average
	INPUT_COURSE_AVERAGE:;
	double courseAverageChar;
   	printf("\nEnter Course Average Between 0 and 100:");
   	scanf("%lf", &courseAverageChar);
	if (courseAverageChar < 0 || courseAverageChar > 100)
	{
	   	printf("\Course Average Is Not Between 1 and 100, Type Again\n");
		goto INPUT_COURSE_AVERAGE;
	}
	courseInfoStruct.courseAverage= courseAverageChar;
	printf("\Course Average: %5.2lf\n",courseAverageChar);
	
	return courseInfoStruct;
}
