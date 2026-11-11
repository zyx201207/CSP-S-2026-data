#include <bits/stdc++.h>
using namespace std;
int main()
{	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,x[100005];
	bool s;
	cin >> n;
	string y[10005],q[100005];
	int num=0,cnt=0;
	for(int i = 0;i < n; i++)
	{
		cin >> x[i] >> y[i];
		for(int j = 0;j < x[i];j++)
		{
			q[num] = y[i];
			num++;
		}
	}
	int a = 0;
	for (int i = num; i > 0; i--)
	{
		if (q[i] == q[a])
		{
			s=1;
		}
		else
		{
			s=0;
		}
		a++;
	}
	if (s=1)
	{
		cout << 0;
	}
	else
	{
		a=0;
		for (int i = num; i > 0; i--)
		{
			if (q[i] != q[a])
			{
				q[a]=q[i];
				cnt++;
			}
		}
	}
	cout << cnt;
	return 0;
}