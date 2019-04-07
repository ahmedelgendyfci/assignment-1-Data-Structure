#include<iostream>
#include<string>
#include <cstddef> 
#include <vector>

using namespace std;

class StudentName
{
private:
	string name;


public:
	StudentName(string str)
	{
		name = str;
		SpaceCounter();
		cout << "-----------------------------------------------------" << endl;
	}

	void SpaceCounter()
	{
		int count = 0;
		for (int i = 0; i < name.size(); i++)
		{
			if (name[i] == ' ')
			{
				++count;
			}
		}
		//cout << "Counter : " << count << endl;
		if (count < 2)
		{
			RepeatName(count);

			print();
		}
		else
		{
			cout << "full name is:" << name << endl << "----------------" << endl;

			print();
		}


	}

	void RepeatName(int count)
	{
		int indexOfSpace = name.find_last_of(" ");
		string subName = name.substr(indexOfSpace + 1, name.size());

		//cout << "substring is:" << subName << endl;

		for (int i = count; i < 2; i++)
		{
			name += " " + subName;
		}

		cout << "full name is:" << name << endl << "----------------" << endl;

	}

	void print(){

		string subName;
		int firstIndexOfSpace = 0,
			lastIndexOfSpace = 0;

		vector<int> myVector;

		for (int i = 0; i < name.size(); i++)
		{
			if (name[i] == ' ')
			{
				myVector.push_back(i);
				
			}

		}

		for (int i = 0; i < myVector.size(); i++)
		{
			//cout << myVector[i] << endl;
			if (i == 0)
			{
				firstIndexOfSpace = 0;
				lastIndexOfSpace = myVector[0]+1;
			}
			else
			{
				firstIndexOfSpace = lastIndexOfSpace;
				lastIndexOfSpace = myVector[i]+1;
			}
			cout << name.substr(firstIndexOfSpace, lastIndexOfSpace - firstIndexOfSpace ) << endl;
		}
		cout << name.substr(lastIndexOfSpace,name.size()) << endl;
	}


};



int main()
{
	StudentName  S1("a");
	StudentName  S2("a b");
	StudentName  S3("a b c");
	StudentName  S4("a b c d");
	StudentName  S5("a b c d e f");


	system("pause");
	return 0;
}