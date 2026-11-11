#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[200005],f[200005],ans[200005],maxn=-1,sum;
bool cmp(int x,int y)
{
	return x>y;
}
void fs(int step)
{
	if(step>m)
	{
		sum=a[ans[1]];
		for(int i=2;i<=m;i++)
		{
			sum&=a[ans[i]];
		}
		if(sum>maxn)
		{
			maxn=sum;
		}
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(f[i]==0)
		{
			f[i]=1;
			ans[step]=i;
			fs(step+1);
			f[i]=0;
		}
	}
	return ;
}
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n<=2000)
	{
		fs(1);
		cout<<maxn;
	}
	else
	{
		sort(a+1,a+n+1,cmp);
		cout<<a[m];
	}
	return 0;
}
