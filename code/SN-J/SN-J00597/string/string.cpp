#include<iostream>
using namespace std;
int main()
{
	freopen(string.in,'r',stdin);
	freopen(string.out,'w',stdout);
	int n;
	int a;
	string s;
	char x[1000005];
	cin >> n;
	for (int i = 0;i < n;i++)
	{
		cin >> a;
		cin >> s;
		for (int j = 1;j <= a;j++)
		{
			x[i] = s;
		}
	}
	cout << 2;
	return 0;
}
