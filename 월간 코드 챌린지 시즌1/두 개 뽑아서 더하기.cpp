#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> numbers)
{
	vector<int> answer;	

	sort(numbers.begin(), numbers.end());

	for (int i = 0; i < numbers.size(); i++)
	{
		for (int j = 0; j < numbers.size(); j++)
		{
			if (i != j && j > i)
			{
				int nTemp = numbers[i] + numbers[j];
				answer.push_back(nTemp);
			}
		}
	}

	sort(answer.begin(), answer.end());
	answer.erase(unique(answer.begin(), answer.end()), answer.end());	

	return answer;
}

int main()
{
	vector<int> vecAnswer = solution({ 2,1,3,4,1 });

	for (int i = 0; i < vecAnswer.size(); i++)
	{
		cout << vecAnswer[i] << " ";
	}

	return 0;
}