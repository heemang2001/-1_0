#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// a의 길이는 1 이상 500,000 이하입니다.
// a의 모든 수는 0 이상 (a의 길이) 미만입니다.

int solution(vector<int> a)
{
	int answer = -1;

	// 각 숫자들이 등장하는 횟수
	vector<int> vecNum(a.size(), 0);

	for (int i = 0; i < a.size(); i++)
	{
		// vecNum[A] = B // a에서 숫자A는 B번 등장
		vecNum[a[i]]++;
	}

	for (int i = 0; i < vecNum.size(); i++)
	{
		// 해당숫자가 등장하지 않았다면 계속
		if (vecNum[i] == 0)
		{
			continue;
		}

		// answer(현재까지 스타수열을 만드는데 사용된 공통된 원소가 가장 많이 사용된 횟수)
		if (vecNum[i] <= answer) 
		{
			continue;
		}

		int Result = 0;

		for (int j = 0; j < a.size() - 1; j++)
		{
			// 인접한 두수에 해당숫자가 없다면 
			if (a[j] != i && a[j + 1] != i)
			{
				continue;
			}

			// 인접한 두수가 같다면
			if (a[j] == a[j+1])
			{
				continue;
			}

			Result++;
			j++;
		}

		answer = max(answer, Result);
	}

	// 길이는 숫자 사용된횟수 * 2
	return answer * 2;
}

int main()
{
	cout << solution({ 0 }) << '\n';					// 0
	cout << solution({ 5,2,3,3,5,3 }) << '\n';			// 4
	cout << solution({ 0,3,3,0,7,2,0,2,2,0 }) << '\n';	// 8

	return 0;
}