#include<iostream>
#include<cstring>
using namespace std;
int a[200005];
int st[200005];
int top=1;
void cp(int n)
{
	int flag=0;
	for(int i=1;i<=top-1;i++)
	{
		if(st[i]==n)
		{
			flag=i;
			break;
		}
	}
	if(flag)
	{
		top=flag+1;
	}
	else 
	{
		st[top++]=n;
	}
}
int ans[300005],cnt[5005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		top=1;
		for(int j=i;j<=n;j++)
		{
			cp(a[j]);
		}
		memset(cnt,0,sizeof cnt);
		for(int i=1;i<=top-1;i++)
		{
			cnt[st[i]]=1;
		}
		for(int i=1;i<=m;i++)
		{
			ans[i]+=cnt[i];
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
}
