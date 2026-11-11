#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
int c[200005];
int s[200005];
int f(int k)
{
	memset(c,0,sizeof(c));
	int cnt=0;
	for(int i=k;i<=n;i++)
	{
		bool b=0,id;
		for(int j=k;j<i;j++)
		{
			if(c[j]==a[i])
			{
				b=1;
			}
			else
			{
				id=j;
			}
		}
		if(b==0)
		{
			cnt++;
			c[cnt]=a[i];
		}
		else
		{
			for(int i=id;i<=cnt;i++)
			{
				c[i]=0;
				
			}
			cnt=id;
		}
	}
	return cnt;
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	bool b1=0;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
		if(i>=2)
		{
			if(a[i-1]>a[i])
			{
				b1=1;
			}
		}
//		cout << n << endl;
	}
	if(b1==0)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]!=a[i+1])
			{
				cout << i << " ";
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		int cnt=f(i);
		for(int i=1;i<=cnt;i++)
		{
			s[c[i]]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout << s[i] << " ";
	}
}