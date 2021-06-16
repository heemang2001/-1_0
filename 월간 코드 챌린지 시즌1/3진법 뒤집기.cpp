#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int solution(int n)
{
	int answer = 0;
	vector<int> vecNum;

	while (1)
	{
		vecNum.push_back(n % 3);

		n = n / 3;

		if (n == 0)
		{
			break;
		}
	}

	reverse(vecNum.begin(), vecNum.end());

	for (int i = 0; i < vecNum.size(); i++)
	{
		answer += pow(3, i) * vecNum[i];
	}

	return answer;
}

int main()
{
	cout << solution(45) << '\n';	// 7;
	cout << solution(125) << '\n';	// 229;
	
	return 0;
}