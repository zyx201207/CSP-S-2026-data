#include<bits/stdc++.h>
using namespace std;
int a[2000005],ans,du[10],c,t,n,d,cnt;
void dfs(int x,int y)
{
	if(x<y) swap(x,y);
	for(int i=x+1;i<=n;i++)
	{
		if(a[i]-a[x]<=d&&a[i]-a[y]<=d)
		{
		    ans++;
		}
		else
		{
			return;
		} 
	}
}
int main()
{
	freopen("migrate","r",stdin);
	freopen("migrate","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		ans=0;
		memset(du,0,sizeof du);
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		int len=1;
		while(len<n)
		{
			cnt=0;
			for(int j=len+1;j<=n;j++)
			{
				if(a[j]-a[len]<=d)
				{
					cnt++;
					du[cnt]=j;
				}
				if(cnt>2)
				{
					len++;
					break;
				}
			}
			if(cnt==2) dfs(du[1],du[2]);
			for(int k=len;k<=du[2];k++)
			{
				if(a[k+1]-a[k]<=d&&a[k+2]-a[k]>d)
				{
					ans++;
				}
			}
			len++;
		}
		cout<<ans<<'\n';
	}
	return 0;
}