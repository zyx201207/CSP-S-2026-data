#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e5+8;
int n,m;
long long v[MAXN],ans;
long long pre[MAXN],suf[MAXN];
void dfs(int step,int cnt,long long val)
{
	if(cnt==m)
	{
		ans=max(ans,val);
		return ;
	}
	else if(m-cnt>n-step+1) return ;
	if(val==0) dfs(step+1,cnt+1,v[step]),dfs(step+1,cnt,val);
	else dfs(step+1,cnt+1,val&v[step]),dfs(step+1,cnt,val);
	return ;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>v[i];
	if(n<=20) dfs(1,0,0),cout<<ans;
	else if(m==1)
	{
		for(int i=1;i<=n;i++) ans=max(ans,v[i]);
		cout<<ans;
	}
	else if(m==2)
	{
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				ans=max(ans,v[i]&v[j]);
		cout<<ans;
	}
	else if(m==n)
	{
		ans=v[1];
		for(int i=2;i<=n;i++) ans&=v[i];
		cout<<ans;
	}
	else if(m==n-1)
	{
		pre[1]=v[1],suf[n]=v[n];
		for(int i=2;i<=n;i++) pre[i]=pre[i-1]&v[i];
		for(int i=n-1;i>=1;i--) suf[i]=suf[i+1]&v[i];
		for(int i=2;i<=n-1;i++) ans=max(ans,pre[i-1]&suf[i+1]);
		cout<<max(ans,max(pre[n-1],suf[2]));
	}
	return 0;
}
