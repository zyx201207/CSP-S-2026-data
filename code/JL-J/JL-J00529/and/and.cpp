/*
  50pts~60pts
  luogu 1842302
  what is the xingzhi of &? I forget
*/
#include<bits/stdc++.h>
using namespace std;
int n,m;
int num(int mask)
{
	int len,ans=0;
	for(int i=1;i<=21;i++)
	{
		if(pow(2,i)>mask) 
		{
			len=i;
			break;
		}
	}
	for(int i=1;i<=len;i++)
	{
		if(mask&(1<<i)) ans++;
	}
	return ans;
}
int a[200001];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	int maxa=-1;
	for(int i=1;i<=n;i++) {cin>>a[i];maxa=max(maxa,a[i]);}
	if(m==1)//#6 1003
	{
		cout<<maxa<<endl;
		return 0;
	}
	if(m==n)//#7 1005
	{
		int ans=a[1];
		for(int i=2;i<=n;i++) ans&=a[i];
		cout<<ans<<endl;
	}
	if(n<=20)//#1 2 3 4 5 1033
	{
		int ans=-1;
		for(int mask=(1<<m);mask<(1<<(n+1));mask++)
		{
			int len,sum=(1<<(n+1))-1;
			for(int i=1;i<=20;i++)
			{
				if(pow(2,i)>mask) 
				{
					len=i;
					break;
				}
			}
			if(num(mask)==m)
			{
				for(int i=1;i<=len;i++)
				{
					if(mask&(1<<i)) sum&=a[i];
				}
				ans=max(ans,sum);
			}
		}
		cout<<ans<<endl;
		return 0;
	}
	if(m==2)//# 8 9 10 1039
	{
		int ans=-1;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;(j<=n)&&(j!=i);j++)
			{
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans<<endl;
		return 0;
	}
	if(m==(n-1))//#11 12 only can 5e4
	{
		int ans=-1;
		for(int i=1;i<=n;i++)
		{
			int sum=(1<<(n+1))-1;
			for(int j=1;j<=n;j++)
			{
				if(j==i) continue;
				sum&=a[j];
			}
			ans=max(ans,sum);
		}
		cout<<ans<<endl;
		return 0;
	}
	cout<<0;
	return 0;
}
