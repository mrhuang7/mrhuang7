#ifndef __CALCULATOR_H
#define __CALCULATOR_H
#include<string>
#include<stack>
#include<vector>
#include"Frac.h"

class Calculator
{
public:
	Calculator();
	

	//�жϷ������ȼ�
	bool Priority(char t_in, char t_out);
	//�ж��Ƿ��Ƿ���
	bool IsOp(char op);
	bool IsOp(std::string op);
	/// <summary>
	/// ����������׺���ʽ
	/// </summary>
	/// <param name="infix"></param>
	/// <returns>���ز�������׺���ʽ</returns>
	std::string SuppleInfix(std::string infix);

	/// <summary>
	/// ��׺���ʽת�ɺ�׺���ʽ
	/// </summary>
	/// <param name="infix"></param>
	/// <returns>�Ƿ�ת���ɹ�������ƥ�䣬�򷵻�false</returns>
	bool ReversePolish(std::string infix);

	/// <summary>
	/// �����沨�����
	/// </summary>
	/// <returns>���ؽ��������׺�����򷵻ؿ�</returns>
	std::string CalcuReversePolish();

	/// <summary>
	/// �õ���׺���ʽջ
	/// </summary>
	/// <param name="infix"></param>
	/// <returns>ջ</returns>
	std::stack<std::string>  GetReversePolish(std::string infix);

	/// <summary>
	/// ���ݺ�׺���ʽ�õ�һ���ӱ��ʽ�Ķ�ά����
	/// </summary>
	/// <param name="reversePolish"></param>
	/// <returns>�ӱ��ʽ�Ķ�ά����</returns>
	std::vector<std::vector<std::string>> GetChildExpression(std::stack<std::string> reversePolish);


	std::string CalResult(std::string num1, std::string num2, std::string op);
	/// <summary>
	/// ������׺�õ����
	/// </summary>
	/// <param name="infix"></param>
	/// <returns>������</returns>
	std::string GetResult(std::string infix);
private:
	std::stack<std::string> number;     //�洢��׺���ʽ
	
public:
	~Calculator();
};

#endif // !__CALCULATOR_H