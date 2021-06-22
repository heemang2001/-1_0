#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// a�� ���̴� 1 �̻� 500,000 �����Դϴ�.
// a�� ��� ���� 0 �̻� (a�� ����) �̸��Դϴ�.

int solution(vector<int> a)
{
	int answer = -1;

	// �� ���ڵ��� �����ϴ� Ƚ��
	vector<int> vecNum(a.size(), 0);

	for (int i = 0; i < a.size(); i++)
	{
		// vecNum[A] = B // a���� ����A�� B�� ����
		vecNum[a[i]]++;
	}

	for (int i = 0; i < vecNum.size(); i++)
	{
		// �ش���ڰ� �������� �ʾҴٸ� ���
		if (vecNum[i] == 0)
		{
			continue;
		}

		// answer(������� ��Ÿ������ ����µ� ���� ����� ���Ұ� ���� ���� ���� Ƚ��)
		if (vecNum[i] <= answer) 
		{
			continue;
		}

		int Result = 0;

		for (int j = 0; j < a.size() - 1; j++)
		{
			// ������ �μ��� �ش���ڰ� ���ٸ� 
			if (a[j] != i && a[j + 1] != i)
			{
				continue;
			}

			// ������ �μ��� ���ٸ�
			if (a[j] == a[j+1])
			{
				continue;
			}

			Result++;
			j++;
		}

		answer = max(answer, Result);
	}

	// ���̴� ���� ����Ƚ�� * 2
	return answer * 2;
}

int main()
{
	cout << solution({ 0 }) << '\n';					// 0
	cout << solution({ 5,2,3,3,5,3 }) << '\n';			// 4
	cout << solution({ 0,3,3,0,7,2,0,2,2,0 }) << '\n';	// 8

	return 0;
}