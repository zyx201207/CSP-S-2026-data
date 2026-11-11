#include<bits/stdc++.h>
#define ll long long
using namespace std;
int c,t,n,m;
int a[1010000];
int cur=0;
ll read()
{
	ll x=1,f=-1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
void dfs(int cnt,int l,int goal)
{
//	cout<<"cnt="<<cnt<<" "<<"l="<<l<<goal<<"\n";
	if(l>goal) return ;
	if(cnt==0)
	{
		if(l==goal) 
		{
	//		cout<<"ggg";
			cur++;
			return ;
		}
		else return ;
	}
	for(int i=1;i<=m;i++)
	{
		dfs(cnt-1,l+i,goal); 
	} 
	return ;
	
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		int ans=0;
		cin>>n>>m;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i+2;j<=n;j++)
			{
				int cnt=(a[j]-a[i])/m;//×î¶ÌÂ·¾¶Îªcnt
				cur=0;
				dfs(cnt+1,i,j);
				if(cur==2) ans++;
			}
		}
		cout<<ans<<"\n";
	}
	
}
