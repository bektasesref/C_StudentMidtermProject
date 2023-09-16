#define MAXCHAR 1000

#define CLASSSIZE 35 // SINIFKAPASITE
#define STUDENTNUMBERLENGTH 10 // OGRENCINUMARAUZUNLUGU
#define NAMELENGTH 25 // ADIUZUNLUGU
#define COURSENAMELENGTH 50 // DERSADIUZUNLUGU
#define COURSECODELENGTH 10 // DERSKODUZUNLUGU
#define COURSELETTERGRADELENGTH 2 // DERSHARFKODUUZUNLUÐU
#define COURSESREGISTERED 5 // KAYITLIDERSLER
#define MIDTERMWEIGHT 30 // VIZEAGIRLIK
#define FINALWEIGHT 30 // FINALAGIRLIK
#define QUIZWEIGHT 20 // QUIZAGIRLIK
#define HOMEWORKWEIGHT 20 // ODEVAGIRLIK

typedef struct fullName{ //tam adi
char name[NAMELENGTH]; //adi
char surname[NAMELENGTH]; //soyadi
}name_t;

typedef struct examGrades{ //sinav not
double midterm; //vize
double final; //final
double quiz; //quiz
double homework; //odev
}grades_t;

typedef struct courseRegistered{ //kayitliDersler
char courseName[COURSENAMELENGTH]; //ders adi
char courseCode[COURSECODELENGTH]; //ders kodu
grades_t grades; //notler
char letterGrade[2]; //harf notu
double numericGrade; //numerik notu
}courseReg_t;

typedef struct studentInfo{ //ogrenci bilgi
name_t studentName; //ogrenci adi
char stNo[STUDENTNUMBERLENGTH]; //ogrenci numara
courseReg_t courses[COURSESREGISTERED]; //dersler
double gpa; //ortalama
}student_t;

typedef struct courseInfo{ //ders bilgi
char courseName[COURSENAMELENGTH]; //ders adi
char courseCode[COURSECODELENGTH]; //ders kodu
student_t students[CLASSSIZE]; //ogrenciler
double courseAverage; //ders ortalama
}courses_t;
