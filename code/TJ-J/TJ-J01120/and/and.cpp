#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],v[200005],ans,cnt,p;
void dfs(int step)
{
	step+=1;
	if(step>m)
	{
		cnt=max(cnt,ans);
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(v[i]==0)
		{
			v[i]=1;
			p=ans;
			if(step==1)ans=a[i];
			else ans=(ans&a[i]);
			dfs(step);
			ans=p;
			v[i]=0;
		}
	}
	return ;
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
	dfs(0);
	cout<<cnt;
	return 0;
} 
