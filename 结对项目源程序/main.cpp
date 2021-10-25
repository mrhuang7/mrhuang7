#include<iostream>
#include<regex>
#include"PriAriCreator.h"

using namespace std;
#pragma warning(disable:26451)

const string helpContext = "help:\n"
"-n [��Ŀ����] -r [��Ȼ������������������ĸ�ķ�Χ]          ������Ӧ��������Ŀ���\n"
"-e [title] -a [answer]     �ֱ��Ӧ��Ŀ�ļ�·������ļ�·��\n";

const string error = "�������� ������help���鿴����\n";


bool IsALLNum(string str)
{
	        regex r("[0-9]*");
  	         smatch result;
	return  regex_match(str, result, r);
}

void Parse(int argc, char** argv)
{
	if (argc == 2)
	{
		if (string(argv[1])._Equal("help"))
		{
			cout << helpContext;
		}
		else
		{
			cout << error;
		}
	}
	else if (argc == 3)
	{
		if (string(argv[1])._Equal("-n") && IsALLNum(argv[2]))
		{
			
			int numTitile = stoi(argv[2]);
			PriAriCreator* Par = new PriAriCreator();
			Par->CreateAriTitlesAndAnswer(numTitile);
			delete Par;
			
			
		}
		else
		{
			cout << error;
		}
	}
	else if (argc == 5)
	{
		if (string(argv[1])._Equal("-e") && string(argv[3])._Equal("-a"))
		{
			
			PriAriCreator* Par = new PriAriCreator();
			if (Par->ReadTitilesAndAnswer(string(argv[2]), string(argv[4])))
			{
				Par->VerificationAnswer();
			}
			delete Par;
		
		}
		else if (string(argv[1])._Equal("-n") && string(argv[3])._Equal("-r")
			&& IsALLNum(argv[2]) && IsALLNum(argv[4]))
		{
			
			int numTitile = stoi(argv[2]);
			long long numNatural = std::stoll(argv[4])-1;
			PriAriCreator* Par = new PriAriCreator();
			Par->CreateAriTitlesAndAnswer(numTitile, numNatural);
			;
		}
		else
		{
			cout << error;
		}
	}
	
	
}

int main(int argc, char** argv)
{
	Parse(argc, argv);
	return 0;
}