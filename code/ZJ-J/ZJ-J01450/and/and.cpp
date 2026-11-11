#include <bits/stdc++.h>
using namespace std;
int n,m,maxn,maxlen,ans,coun=30;
bool a[200003][33],b[200003],x=0;
void f(int p,int h)
{
	ans=max(ans,h);
	if (p<=0)
	{
		return;
	}
	int x=0;
	for (int j=1;j<=n;j++)
	{
		if (a[j][p]&&b[j])
		{
			x++;
		}
		else
		{
			b[j]=0;
		}
	}
	if (x>=m)
	{
		x=1;
		h+=(int)pow(2,p-1);
		f(p-1,h);
	}
	else
	{
		if (x)
		{
			f(p-1,h);
		}
		else
		{
			for (int i=1;i<=n;i++)
			{
				b[i]=1;
			}
			coun--;
			f(coun,0);
		}
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		b[i]=1;
		int x;
		cin>>x;
		int c=0;
		while (x>0)
		{
			c++;
			a[i][c]=bool(x%2);
			x/=2;
		}
		maxlen=max(maxlen,c);
	}
	f(30,0);
	cout<<ans;
	return 0;
}
