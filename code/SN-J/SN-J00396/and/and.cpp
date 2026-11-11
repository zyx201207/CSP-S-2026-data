#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],w[200005][35],vis[200005],ans[35];
long long ANS;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		for(int j=1;j<=31;j++)
		{
			w[i][j]=a[i]&1;
			a[i]>>=1;
		}
	}
	
	for(int j=31;j>=1;j--)
	{
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			if(!vis[i])cnt+=w[i][j];
		}
	
		if(cnt>=m)
		{
			for(int i=1;i<=n;i++)if(!w[i][j])vis[i]=1;
			ans[j]=1;
		}
	}
	for(int i=1;i<=31;i++)
	{
		
		ANS+=1ll*ans[i]*(1<<(i-1));
	}
	cout<<ANS;
	return 0;
} 
