#include<bits/stdc++.h>//骗分hhh 
using namespace std;//先特判A,B,然后再dfs； 
int a[500010];
int d[500010];//代价
int main() 
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int f=0;//AorB。。。性质A包含在B里面，so只判一个  
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(i>2&&(a[i]-a[i-1]!=a[i-1]-a[i-2]))
		{
			f=1;
		}
	}
	sort(a+1,a+1+n);
	if(f==0)
	{
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			if(i*(i-1)/2*(a[2]-a[1])<=m)
			{
				ans=i;
			}
		}
		cout<<ans;
		return 0;
	}
	int yyy=0;//最大的那个 
	for(int i=1;i<=n;i++)//都变成a[i] 
	{
		int j=i,ans=0,sum=0;
		while(j>=1&&m>=sum)
		{
			ans++;
			sum+=a[i]-a[j];
			j--;
		}
		yyy=max(yyy,ans);
	}
	cout<<yyy;
	return 0;
}
