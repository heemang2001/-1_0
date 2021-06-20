#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int One;
int Zero;
bool bSame = true;

void Divide(vector<vector<int>> arr)
{
	int mid = arr.size() / 2;

	int nTemp2 = arr[0][0];
	for (int i = 0; i < arr.size(); i++)
	{
		for (int j = 0; j < arr.size(); j++)
		{
			if (nTemp2 != arr[i][j] && bSame)
			{
				bSame = false;
				break;
			}
		}
	}

	if (bSame)
	{
		if (nTemp2 == 1)
		{
			One++;
		}

		else
		{
			Zero++;
		}

		return;
	}

	// 사각형 길이가 1인경우
	else if (mid < 1)
	{
		for (int i = 0; i < arr.size(); i++)
		{
			for (int j = 0; j < arr.size(); j++)
			{
				if (arr[i][j] == 1)
				{
					One++;
				}

				else
				{
					Zero++;
				}
			}
		}

		return;
	}

	// 사격형 길이가 2이상인 경우 + 모든 원소가 같지않은 경우
	else if (mid >= 1 && !bSame)
	{
		vector<vector<int>> vecLeftUp(mid);
		vector<vector<int>> vecRightUp(mid);
		vector<vector<int>> vecLeftDown(mid);
		vector<vector<int>> vecRightDown(mid);

		// 왼쪽 위
		for (int i = 0; i < mid; i++)
		{
			for (int j = 0; j < mid; j++)
			{
				vecLeftUp[i].push_back(arr[i][j]);
			}
		}

		int nTemp = vecLeftUp[0][0];
		bool bTemp = false;
		for (int i = 0; i < vecLeftUp.size(); i++)
		{
			for (int j = 0; j < vecLeftUp.size(); j++)
			{
				if (nTemp != vecLeftUp[i][j] && !bTemp)
				{
					bTemp = true;
					Divide(vecLeftUp);
				}
			}
		}

		if (bTemp == false)
		{
			if (nTemp == 1)
			{
				One++;
			}

			else
			{
				Zero++;
			}
		}


		// 오른쪽 위
		for (int i = 0; i < mid; i++)
		{
			for (int j = mid; j < arr.size(); j++)
			{
				vecRightUp[i].push_back(arr[i][j]);
			}
		}

		nTemp = vecRightUp[0][0];
		bTemp = false;
		for (int i = 0; i < vecRightUp.size(); i++)
		{
			for (int j = 0; j < vecRightUp.size(); j++)
			{
				if (nTemp != vecRightUp[i][j] && !bTemp)
				{
					bTemp = true;
					Divide(vecRightUp);
				}
			}
		}

		if (bTemp == false)
		{
			if (nTemp == 1)
			{
				One++;
			}

			else
			{
				Zero++;
			}
		}

		// 왼쪽 밑
		for (int i = mid; i < arr.size(); i++)
		{
			for (int j = 0; j < mid; j++)
			{
				vecLeftDown[i - mid].push_back(arr[i][j]);
			}
		}

		nTemp = vecLeftDown[0][0];
		bTemp = false;
		for (int i = 0; i < vecLeftDown.size(); i++)
		{
			for (int j = 0; j < vecLeftDown.size(); j++)
			{
				if (nTemp != vecLeftDown[i][j] && !bTemp)
				{
					bTemp = true;
					Divide(vecLeftDown);
				}
			}
		}

		if (bTemp == false)
		{
			if (nTemp == 1)
			{
				One++;
			}

			else
			{
				Zero++;
			}
		}

		// 오른쪽 밑
		for (int i = mid; i < arr.size(); i++)
		{
			for (int j = mid; j < arr.size(); j++)
			{
				vecRightDown[i - mid].push_back(arr[i][j]);
			}
		}

		nTemp = vecRightDown[0][0];
		bTemp = false;
		for (int i = 0; i < vecRightDown.size(); i++)
		{
			for (int j = 0; j < vecRightDown.size(); j++)
			{
				if (nTemp != vecRightDown[i][j] && !bTemp)
				{
					bTemp = true;
					Divide(vecRightDown);
				}
			}
		}

		if (bTemp == false)
		{
			if (nTemp == 1)
			{
				One++;
			}

			else
			{
				Zero++;
			}
		}
	}
}

vector<int> solution(vector<vector<int>> arr)
{
	vector<int> answer;

	Divide(arr);

	answer.push_back(Zero);
	answer.push_back(One);

	return answer;
}

int main()
{
	//vector<int> vecAnswer = solution({ {1,1,0,0} ,{1,0,0,0},{1,0,0,1},{1,1,1,1} });	// 4, 9
	//vector<int> vecAnswer = solution({ {1,1,1,1,1,1,1,1} ,{0,1,1,1,1,1,1,1},{0,0,0,0,1,1,1,1},{0,1,0,0,1,1,1,1},{0,0,0,0,0,0,1,1},{0,0,0,0,0,0,0,1},{0,0,0,0,1,0,0,1},{0,0,0,0,1,1,1,1} });	// 10, 15
	vector<int> vecAnswer = solution({ { 0,0 }, { 0,0 } }); // 1, 0

	for (int i = 0; i < vecAnswer.size(); i++)
	{
		cout << vecAnswer[i] << " ";
	}

	return 0;
}