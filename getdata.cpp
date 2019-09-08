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
	
	student *stu = new student[160000];
	srand((int)time(0));
	for (long i = 0; i < 160000; i++)
	{
		stu[i].number = i + 1;

		stu[i].filenum = rand() % 16 + 1;

		stu[i].height = rand() % 40 + 150 + double(rand()%100)/10;

		int n = rand() % 7 + 4;
		stu[i].name = new char[n + 1];
		for (int j = 0; j < n; j++)
		{
			stu[i].name[j] = char(rand() % 26 + 97);
		}
		stu[i].name[n] = '\0';

		stu[i].area = char(rand() % 4 + 67);

		stu[i].age = rand()% 6 + 17;

		random_device rd;
		mt19937 gen(rd());
		normal_distribution<double> no(82,5);
		unsigned v = 0;
		while (v < 50)
		{
			v = no(gen);
			v = v%100;
		}
		double little = double(rand() % 100) / 100;
		stu[i].score = v + little;//高斯正态函数normal_distribution
	}

	for (int k = 0; k < 16; k++)
	{
		ofstream output;
		string str1,str2;
		str1 = "d:\\data_struct\\data";
		string numberStr = to_string(k + 1);
		str1 += numberStr;
		str2 = str1 + ".txt";
		output.open(str2);
		for (int i = 0; i < 160000; i++)
		{
			if (stu[i].filenum == k + 1)
			{
				output << stu[i].number << '-' << stu[i].filenum << '-' << stu[i].name << '-' << stu[i].area << '-' << stu[i].age << '-';
				output << setiosflags(ios::fixed) << setprecision(1);
				output << stu[i].height << '-';
				output << setiosflags(ios::fixed) << setprecision(2);
				output << stu[i].score << endl;
			}
		}
		output.close();
	}

	for (int k = 0; k < 16; k++)
	{
		ofstream output;
		string str1, str2;
		str1 = "d:\\data_struct\\data";
		string numberStr = to_string(k + 1);
		str1 += numberStr;
		str2 = str1 + ".dat";
		output.open(str2, ios::out | ios::binary);
		for (int i = 0; i < 160000; i++)
		{
			if (stu[i].filenum == k + 1)
			{
				output.write((char*)(&stu[i]), sizeof(stu[i]));
			}
		}
		output.close();
	}
	
	for (int i = 0; i < 160000; i++)
	{
		cout << stu[i].number << '-' << stu[i].filenum << '-' << stu[i].name << '-' << stu[i].area << '-'<< stu[i].age<<'-';
		cout << setiosflags(ios::fixed) << setprecision(1);
		cout << stu[i].height << '-'  ;
		cout << setiosflags(ios::fixed) << setprecision(2);
		cout << stu[i].score<<endl;
		delete[]stu[i].name;
	}
	delete[]stu;

	system("pause");
	return 0;
}