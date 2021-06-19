#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(int n)
{
	vector<vector<int>> MAP(n + 1, vector<int>(n + 1));
	vector<int> answer;

	// 1+2+3+4+...+n // �������� �����
	int Max_Num = (n * (n + 1)) / 2;

	//	- Top : ���� ä������ ���� ���� �� ���� �ǹ��Ѵ�.
	//	- Bottom : ���� ä������ ���� ���� �Ʒ����� �ǹ��Ѵ�.
	//	- Left : ���� ä������ ���� ���� �������� �ǹ��Ѵ�.
	//	- Right : ���� ä������ ���� ���� ������ ���� �ǹ��Ѵ�.
	int Top = 1;
	int Bottom = n;
	int Left = 1;
	int Right = 0;

	int Num = 1;
	int State = 0;

	while (Num <= Max_Num)
	{
		// ���ʿ��� �Ʒ���
		if (State == 0) 
		{
			for (int i = Top; i <= Bottom; i++)
			{
				MAP[i][Left] = Num++;
			}

			Top++;
			Left++;
			State = 1;
		}

		// �Ʒ����� ����������
		else if (State == 1)
		{
			for (int i = Left; i <= Bottom - Right; i++)
			{
				MAP[Bottom][i] = Num++;
			}

			Bottom--;
			State = 2;
		}

		// �����ʿ��� ����
		else if (State == 2)
		{
			for (int i = Bottom; i >= Top; i--)
			{
				MAP[i][i - Right] = Num++;
			}

			Right++;
			Top++;
			State = 0;
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			answer.push_back(MAP[i][j]);
		}
	}

	return answer;
}

int main()
{
	vector<int> vecAnswer = solution(4); // [1,2,9,3,10,8,4,5,6,7]
	//vector<int> vecAnswer = solution(5); // [1,2,12,3,13,11,4,14,15,10,5,6,7,8,9]
	//vector<int> vecAnswer = solution(6); // [1,2,15,3,16,14,4,17,21,13,5,18,19,20,12,6,7,8,9,10,11]

	for (int i = 0; i < vecAnswer.size(); i++)
	{
		cout << vecAnswer[i] << " ";	
	}

	return 0;
}