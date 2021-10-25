#ifndef __PRIARICREATOR_H
#define __PRIARICREATOR_H
#include<fstream>
#include<random>
#include<time.h>
#include<string>
#include"Calculator.h"

class PriAriCreator
{
public:
	PriAriCreator();
	~PriAriCreator();

	/// <summary>
	/// ������Ŀ(��Ŀ��������Ȼ����Χ���������Χ���������ĸ)
	/// </summary>
	/// <param name="titleNums"></param>
	/// <param name="naturlrange"></param>
	/// <param name="uprange"></param>
	/// <param name="downrange"></param>
	bool CreateAriTitlesAndAnswer(int titleNums = 10, long long naturlrange = 10);

	/// <summary>
	/// ��ȡ�ļ�����Ŀ
	/// </summary>
	/// <param name="titlesname"></param>
	bool ReadTitilesAndAnswer(std::string titlefilename, std::string answerfilename);

	/// <summary>
	/// ��֤��
	/// </summary>
	void VerificationAnswer();

	/// <summary>
	/// �ж���Ŀ�Ƿ�����
	/// </summary>
	/// <param name="scource"></param>
	/// <param name="destination"></param>
	/// <returns>bool</returns>
	bool IsSimilary(std::string scource, std::string destination);

	bool IsCreaateNegative(std::string expression);

	bool IsDownZero(std::string expression);
	/// <summary>
	/// �ж������ӱ��ʽ�Ƿ�ȼ�
	/// </summary>
	/// <param name="exp"></param>
	/// <param name="exp2"></param>
	/// <returns>bool</returns>
	bool Cmp_ExChild(std::vector<std::string> ex1, std::vector<std::string>ex2);

	long long random_LL(long long min, long long max, unsigned int seed = time(nullptr));

	int random_Int(int min, int max, unsigned int seed = time(nullptr));

	std::string random_OP();

	std::string CreateAnswer(std::string infix);

	void SaveTitleToFile();
	void SaveAnswerToFile();
private:
	Calculator	mCalculator;								//������
	const int mOpNumMax = 3;								//������������
	std::vector<std::string>	mInfixs;					//���ɵ���Ŀ
	std::vector<std::string>	mAnswers;					//��Ŀ�Ĵ�


	std::ofstream  mTitleFile;								//��Ŀ�ļ���
	std::ofstream  mAnswerFile;								//���ļ���

	std::default_random_engine mDre;
};
#endif // !__PRIARICREATOR_H