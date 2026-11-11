#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
const int N=5e5+5;
int a[N],Max,Min=1e18;
bool checkA()
{
	for(int i=1;i<=n;i++)if(a[i]!=i)return false;
	return true;
}
bool checkB()
{
	for(int i=2;i<n;i++)
	{
		if((a[i]-a[i-1])!=(a[i+1]-a[i]))return false;
	}
	return true;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
//	system("fc myT1.out crystal4.ans");
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		a[i]+=100;
		Max=max(Max,a[i]);
		Min=min(Min,a[i]);
	}
	sort(a+1,a+n+1);
	if(n<=5000)
	{
		int ans=1;
		for(int i=2;i<=n;i++)
		{
			int res=0,now=1;
			for(int j=i-1;j>0;j--)
			{
				res+=abs(a[i]-a[j]);
				if(res>m)break;
				now++;
			}
			ans=max(ans,now);
		}
		cout<<ans;
		return 0;
	}
	else if(Max<=200)
	{
		int ans=1;
		for(int i=Min+1;i<=Max;i++)
		{
			int ji=0;
			for(int j=1;j<=n;j++)
			{
				if(a[j]>i)
				{
					ji=j-1;
					break;
				}
			}
//			cout<<ji<<' ';
			int res=0,now=0;
			for(int j=ji;j>0;j--)
			{
				res+=abs(i-a[j]);
				if(res>m)break;
				now++;
			}
			ans=max(ans,now);
		}
		cout<<ans;
		return 0;
	}
	else if(checkA()||checkB())
	{
		int ans=1,res=0;
		for(int i=1;i<=n;i++)
		{
			res=res+i*(a[i+1]-a[i]);
			if(res>m)break;
			ans++;
		}
		cout<<ans;
	}
	return 0;
}
