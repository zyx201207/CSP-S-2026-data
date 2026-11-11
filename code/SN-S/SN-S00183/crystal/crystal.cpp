#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int n,ans;
int m;
int a[N];
int fi=1,fj=1; 
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	cin>>a[1]>>a[2];
	if(a[1]!=1 or a[2]!=2)
	{
		fi=0;
	}
	int cha=a[2]-a[1];
	for(int i=3;i<=n;i++)
	{
		int chai;
		cin>>a[i];
		chai=a[i]-a[i-1];
		if(a[i]!=i)
		{
			fi=0;
		}
		if(chai!=cha)
		{
			fj=0;
		}
	}
	if(fi==1)
	{
		int now=0,jia=1;
		while(now<=m)
		{
			now+=jia;
			jia++;
			if(ans>=n)
			{
				break;
			}
			ans++; 
		}
		cout<<ans;
	}
	else if(fj==1)
	{
		int now=0,jia=cha;
		while(now<=m)
		{
			now+=jia;
			jia+=cha;
			if(ans>=n)
			{
				break;
			}
			ans++; 
		}
		cout<<ans;
	}
	else//n^2
	{
		sort(a+1,a+n+1);
		if(m>=((a[n]-a[1])*(n-1)))
		{
			cout<<n;
			return 0;
		}
		for(int i=n;i>=1;i--)
		{
			if(n<=ans)
			{
				break;
			}
			int now=0;
			for(int j=i-1;j>=1;j--)
			{
				now=now+a[i]-a[j];
				if(now<=m)
				{
					ans=max(ans,i-j+1);
				}
				else
				{
					break;
				}
			}
		}
		cout<<ans;
	}
	return 0;
}
