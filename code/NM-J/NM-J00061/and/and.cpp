#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n,m,a[200050],tot;
bool has[200050][50],cant[200050];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		int w=0;
		while(a[i]!=0)
		{
			has[i][w]=a[i]&1;
			a[i]>>=1;
			w++;
		}
	}
	for(int i=49;i>=0;i--)
	{
		ll num=0;
		for(int j=1;j<=n;j++)
		{
			if(!cant[j])
			num+=has[j][i];
		}
		if(num>=m)
		{
			tot|=1<<i;
			for(int j=1;j<=n;j++)
			{
				if(!cant[j])
				cant[j]=!has[j][i];
			}
		}
	}
	cout<<tot;
}
