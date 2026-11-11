//钟林希 西安翱翔中学 SN-J00675 
#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200050];
long long ans=0;
void dfs(int step,int sum,long long num)
{
	if(num==0)return ;
	if(sum>m)return ;
	if(step>n)
	{
		if(sum==m)ans=max(ans,num);
		return ;
	}
	if(num==-1e9)dfs(step+1,sum+1,a[step]);
	else dfs(step+1,sum+1,num&a[step]);
	dfs(step+1,sum,num);
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	dfs(1,0,-1e9);
	printf("%lld",ans);
	return 0;
}
