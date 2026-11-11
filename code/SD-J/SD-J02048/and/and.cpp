#include<iostream>
#include<cstring>
#include<ctime>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<set>
#include<map>
#include<list>
#include<stack>
using namespace std;
int a[200010],ans,num;
int n,m;
void dfs(int step,int sum,int cnt)
{
	if(cnt==m)
	{
		ans=max(ans,sum);
		return;
	}
	if(step==n)    return;
	dfs(step+1,sum,cnt);
	dfs(step+1,sum&a[step+1],cnt+1);
}
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)    cin>>a[i];
	if(n<=20)
	{
		dfs(0,2147483647,0);
		cout<<ans;
	}
	else if(m==n)
	{
		num=a[1];
		for(int i=2;i<=n;i++)    num&=a[i];
		cout<<num;
	}
	else
	{
		sort(a+1,a+1+n,cmp);
		cout<<endl;
		cout<<a[m];
	}
	return 0;
}
//1 3 7 15 31 63 127
