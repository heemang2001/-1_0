#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> a)
{
	int answer = 0;
	int Lenth = a.size();

	vector<int> vecLeft(Lenth);
	vector<int> vecRight(Lenth);

	if (Lenth > 3)
	{
		// ���� �ּڰ�
		int min = a[0];
		for (int i = 0; i < Lenth; i++)
		{
			if (min > a[i])
			{
				min = a[i];
			}

			vecLeft[i] = min;
		}

		// ������ �ּڰ�
		min = a[Lenth - 1];
		for (int i = Lenth - 1; i >= 0; i--)
		{
			if (min > a[i])
			{
				min = a[i];
			}
			
			vecRight[i] = min;
		}

		for (int i = 0; i < Lenth; i++)
		{
			// ���� ���ʰ� or �����ʰ� 1���� ū��?
			if (a[i] <= vecLeft[i] || a[i] <= vecRight[i])
			{
				answer++;
			}
		}
	}

	else
	{
		answer = Lenth;
	}	
	
	return answer;
}

int main()
{
	//cout << solution({ 9,-1,-5 }) << '\n';								// 3
	cout << solution({ -16,27,65,-2,58,-92,-71,-68,-61,-33 }) << '\n';	// 6

	return 0;
}