#include <iostream>
#include <string>

int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	std::cin >> n;
	std::string s;
	while(n --)
	{
		int x;
		char ch;
		std::cin >> x >> ch;
		while(x --)
		{
			s.push_back(ch);
		}
	}
	long long cnt = 0;
	for(int i = 0;i < s.size() / 2;i ++)
	{
		cnt += s[i] != s[s.size() - 1 - i];
	}
	std::cout << cnt << '\n';
	return 0;
}

// His judgement cometh and that right soon
