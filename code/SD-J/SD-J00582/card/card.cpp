#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[355555],tong[355555],st[355555];
bool p[355555];
void solve()
{
	for(int i=1;i<=n;i++)
	{
		
		for(int j=i;j<=n;j++)
		{
			if(!st[a[j]])
			{
				tong[a[j]]++;
				st[a[j]]=1;
			}
		}for(int j=1;j<=m;j++)st[j]=0;
	}
	for(int i=1;i<=m;i++)cout<<tong[i]<<" ";

}
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	bool flag=1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i-1]>a[i])flag=0;
	}
	if(flag&&n>=500)
	{
		solve();
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			st[a[j]]=0;
			p[j]=1;
		}
		
		for(int j=i;j<=n;j++)
		{
			if(!st[a[j]])
			{
				st[a[j]]=j;
				
			}else
			{
			//	cout<<st[a[j]]<<" "<<j-1<<"\n";
				for(int k=st[a[j]];k<j;k++)
				{
					st[a[k]]=0;
					p[k]=0;
				}
				st[a[j]]=j;
			}
		}
		for(int j=i;j<=n;j++)
		{
			if(p[j])tong[a[j]]++;
		}
	
	 } 
		for(int j=1;j<=m;j++)
	{
		cout<<tong[j]<<" ";
	}

	return 0;
}

