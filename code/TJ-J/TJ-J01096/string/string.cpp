#include<bits/stdc++.h> 
using namespace std;
const int N=1e5+10;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	int a[N];
	char b[N]; 
	char c[N];
	int sum=0;
	for(int i=1;i<=n; i++)
	{
		cin >> a[i] >> b[i];
		sum+=a[i];
	}
	for(int i=1;i<=n; i++)
	{
		for(int j=1;j<=a[i]; j++)
		{
			c[i] = b[i];
		}
	}
	int qwe=0;
	for(int i=1;i<=n; i++)
	{
		if(c[i]==c[i+1])
		{
			qwe++;
		}
	}
	if(qwe==sum)
	{
		cout << 0;
		return 0;
	}
	char d[N];
	char e[N];
	int xiu=0;
	if(sum%2==1)
	{
		for(int i=0;i<sum/2+1; i++)
		{
			d[i]=c[i];
		}
		for(int j=0;j>=sum/2+1-sum; j--)
		{
			e[j]=c[j];
		}
		for(int i=1;i<=sum/2; i++)
		{
			if(d[i]!=e[i])
			{
				xiu++;
			}
		}
	}
	else
	{
		for(int i=0;i<sum/2; i++)
		{
			d[i]=c[i];
		}
		for(int j=0;j>=sum/2-sum; j--)
		{
			e[j]=c[j];
		}
		for(int i=1;i<=sum/2; i++)
		{
			if(d[i]!=e[i])
			{
				xiu++;
			}
		}
	}
	cout << xiu;
	return 0;
 }

