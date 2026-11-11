#include<bits/stdc++.h>
using namespace std;
long long a[200005][35],n,m,x,ans,cnt;
bool vis[200005];
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>x;
		for(int k=0;k<=30;k++)
		{
			a[i][k]=x&(1<<k);
		}
	}
	for(int i=30;i>=0;i--)
	{
		cnt=0;
		for(int j=0;j<n;j++)
		{
			if(a[j][i]!=0&&!vis[j])
			{
				cnt++;
			}
		}
		if(cnt>=m)
		{
			ans+=(1<<i);
			for(int j=0;j<n;j++)
			{
				if(a[j][i]==0)
				{
					vis[j]=true;
				}
			}
		}
	}
	cout<<ans;
}
