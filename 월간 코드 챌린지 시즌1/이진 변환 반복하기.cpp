#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string BinaryConvert(int Num)
{
	string sTemp = "";

	while (1)
	{
		sTemp += to_string(Num % 2);

		Num = Num / 2;

		if (Num == 0)
		{
			break;
		}
	}

	reverse(sTemp.begin(), sTemp.end());

	return sTemp;
}

vector<int> solution(string s)
{
	vector<int> answer;

	int nValue = 0;
	int DeleteZero = 0;
	string strBinary = s;

	while (1)
	{
		if (strBinary == "1")
		{
			break;
		}

		nValue++;

		for (int i = 0; i < strBinary.size(); i++)
		{
			if (strBinary[i] == '0')
			{
				DeleteZero++;
				strBinary.erase(strBinary.begin() + i);
				i--;
			}
		}

		int LenthDeleteZero = strBinary.size();
		strBinary = BinaryConvert(LenthDeleteZero);
	}

	answer.push_back(nValue);
	answer.push_back(DeleteZero);

	return answer;
}

int main()
{
	//vector<int> vecAnswer = solution("110010101001");	// 3, 8
	//vector<int> vecAnswer = solution("01110");			// 3, 3
	//vector<int> vecAnswer = solution("1111111");		// 4, 1
	vector<int> vecAnswer = solution("0000001");		

	for (int i = 0; i < vecAnswer.size(); i++)
	{
		cout << vecAnswer[i] << " ";
	}

	return 0;
}