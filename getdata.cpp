#include<iostream>
#include<ctime>
#include<cstdlib>
#include<iomanip>
#include <random>
#include<fstream>
#include<string>

using namespace std;

class student
{
public:
	int number;
	double score;
	char* name;
	int age;
	int filenum;
	double height;
	char area;
};
int main()
{
	
	student *stu = new student;
	cout << sizeof(stu);
	delete stu;

	system("pause");
	return 0;
}