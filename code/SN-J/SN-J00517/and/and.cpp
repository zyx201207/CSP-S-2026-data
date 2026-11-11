#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[200005];
long long ans[200005];
long long sum=0,maxx=LONG_MIN;
void dfs(long long x,long long y,long long z)
{
	if(x>m)
	{
		maxx=max(maxx,sum);
		return;
	}
	else
	{
		 for(long long i=y+1;i<=n;i++)
		 {
		 	if(x==1)
		 	{
		 		sum=a[i];
		 		dfs(x+1,i,sum);
			}
			else
			{
				sum=sum&a[i];
				dfs(x+1,i,sum);
				sum=z;
			}
		 }
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout); 
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	dfs(1,0,sum);
	cout<<maxx;
	return 0;
}

