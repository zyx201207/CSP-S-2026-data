#include<bits/stdc++.h>
using namespace std;
int n,a[100001],maxn=-1,x[1000001],m;
bool cmp(int x,int y)
{
	return x>y;
}
void dfs(int k,int y)
{
	if(k>m)
	{
		maxn=max(maxn,y);
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(x[i]==0)
		{
			x[i]=1;
			dfs(k+1,y&a[i]);
			x[i]=0;
		}
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n>2000)
		{
			bool f=false;
			long long v;
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=i;j++)
				{
					v=v*2;
				}
				if(a[1]==v-1&&a[1]!=0)
				{
					f=true;
					break;
				}
			}
			if(f==true)
			{
				sort(a+1,a+1+n,cmp);
				cout<<a[m];
				return 0;
			}
			else
			{
				bool flag=true;
				for(int i=1;i<=n;i++)
				{
					if(a[i]!=i-1)
					{
						flag=false;
					}
				}
				if(flag==true)
				{
					cout<<0;
				}
			}
	}
	for(int i=1;i<=n;i++)
	{
		x[i]=1;
		dfs(2,a[i]);
		x[i]=0;
	}
	cout<<maxn;

}