#include<iostream>
using namespace std;
int main()
{
	freopen(and.in,'r',stdin);
	freopen(and.out,'w',stdout);
	int n,m;
	cin >> n >> m;
	int s[100005];
	int x;
	int c;
	for (int i = 0;i < n;i++)
	{
		cin >> x;
		s
		[i] = x;
	}
	for (int i = 0;i < n;i++)
	{
		if ((s[i] & s[i+1]) >= c)
			c = s[i] & s[i+1];
	}
	cout << c;
	return 0;
}
