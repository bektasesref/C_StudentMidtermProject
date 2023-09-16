# C_StudentMidtermProject
C project for midterm of some of my friend that creates database for added students/courses. Calculators for GPA and coruse grade(/average), displayers with the deserialized data from database file

There are 1 C and 5 header file.
•  Main.c: Entry point and main program
•  File_io.h: All the stuff related to database and file input output.
•  Module_addStudent.h: Module to add student. It creates student_t struct to return
•  Module_addCourse.h: Module to add course. It creates course_t struct to return
•  Types.h: Structs & definitons stored in this header
•  Ui.h: UI part of the program. Defines what to do by the keyboard inputs
•  Util.h: Calculations, common use functions etcetra


Entry point starts with the following function
CheckIfDatabaseExists: This function returns the existence of “Database.db” file that we used to store our DB. If it’s 1; it means there is a file. Vice versa; no any database file created. In this particular situation, we jump right to next function;
CreateDatabase: This method Is used to create an empty Database file

PrintWelcomeScreenSelections: Prints all the functions (from 1 to 8) to the terminal with the wanted formatting type
GetSelection: Get the digit input of welcome screen selection. Only accepts from 1 to 8.

SetSelection: Determines what to do according to the chosen option(/selection).
1.  Add Student
2.  Add Course
3.  Calculate Student Course Grade
4.  Calculate Student GPA
5.  Display Student Info
6.  Display Course Info
7.  Print Class
8.  Calcualte Course Average

CalculateStudentCourseGrade: Calculates the student course with the related weight of exam type (final, quiz, homework and midterm).
CalculateStudentGPA: Calculates the student GPA from 0.0 to 4.0 with all the course student have with the related weight of exam type (final, quiz, homework and midterm).
WriteToDatabaseStudentInfo: Writes the information of student to the database name. It serializes student_t struct.
ReadFromDatabaseStudentInfo: Reads the information of student from the database name. It deserializes and creates student_t struct. 
ReadFromDatabase: Reads all the database. Used in test purpose only.
WriteToDatabase: Append string to the database. Used in test purpose only.
