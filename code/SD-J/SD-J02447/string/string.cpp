#include<iostream>
#define int long long
using namespace std;
int n,ans,s[200010];
char f[200010];
void dfs(int l,int r,int vl,int vr,char fl,char fr)
{
	if(l>=r)	return ;
	if(fl==fr)
	{
		if(vl==vr)	dfs(l+1,r-1,s[l+1],s[r-1],f[l+1],f[r-1]);
		else if(vl>vr)	dfs(l,r-1,vl-vr,s[r-1],fl,f[r-1]);
		else	dfs(l+1,r,s[l+1],vr-vl,f[l+1],fr);
	}
	else if(fl!=fr)
	{
		if(vl==vr)
		{
			ans+=vl;
			dfs(l+1,r-1,s[l+1],s[r-1],f[l+1],f[r-1]);
		}
		else if(vl>vr)
		{
			ans=ans+vr;
			dfs(l,r-1,vl-vr,s[r-1],fl,f[r-1]);
		}
		else
		{
			ans=ans+vl;
			dfs(l+1,r,s[l+1],vr-vl,f[l+1],fr);
		}
	}
	return ;
}
signed main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i]>>f[i];
	}
	dfs(1,n,s[1],s[n],f[1],f[n]);
	cout<<ans;
	return 0;
}

