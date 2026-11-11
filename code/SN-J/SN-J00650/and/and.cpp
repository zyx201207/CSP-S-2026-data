//chenshiyun xianaoxiangzhongxue SN-J00650
#include<bits/stdc++.h>
using namespace std;
int ans,num,n,m,a[200005],maxn,an;
void dfs(int step,int cnt)
{
	int it=num;
	if(cnt==0)num=a[step];
	if(cnt>m||step>n)
	{
		if(cnt>=m)ans=max(ans,num);
		return ;
	}
	num&=a[step];
	dfs(step+1,cnt+1);
	num=it;
	dfs(step+1,cnt);
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		maxn=max(maxn,a[i]);
		if(i==1)an=a[1];
		an&=a[i];
	}
	if(m==1)
	{
		printf("%d",maxn);
		return 0;
	}
	if(m==n)
	{
		printf("%d",an);
		return 0;
	}
	dfs(1,0);
	printf("%d",ans);
	return 0;
}
