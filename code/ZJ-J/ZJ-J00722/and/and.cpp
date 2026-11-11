#include <bits/stdc++.h>
using namespace std;
int n,m,p[40];
bool b[200010][40],opt[200010][40];
int a[200010];
bool cmp(int xx,int yy)
{
	return xx > yy;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	p[31] = 1;
	for(int i = 30;i >= 1;i--) p[i] = p[i + 1] * 2;
	for(int i = 1;i <= n;i++)
	{
		cin>>a[i];
		int x = a[i];
		for(int j = 1;j <= 31;j++)
			if(x >= p[j]) x -= p[j],b[i][j] = 1;
	}
	for(int j = 1;j <= 31;j++)
	{
		int u = 0;
		for(int i = 1;i <= n;i++)
			if(b[i][j]) u++;
		if(u >= m)
		{
			for(int i = 1;i <= n;i++)
			if(b[i][j]) opt[i][j] = 1;
		}
	}
	for(int i = 1;i <= n;i++)
	{
		a[i] = 0;
		for(int j = 1;j <= 31;j++)
			if(opt[i][j]) a[i] += p[j];
	}
	sort(a + 1,a + 1 + n,cmp);
	cout<<a[m];
	return 0;
}
