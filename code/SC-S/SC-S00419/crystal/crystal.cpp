#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5+10;
int n,m,a[N],ans=-1,mp[N];
int mx=-1,mi=1e9;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		for(int j=a[i-1];j<a[i];j++)
			mp[j]=i-1;
		mx=max(mx,a[i]);
		mi=min(mi,a[i]);
	}
	mp[mx]=n;
	for(int i=mx;i>=mi;i--) 
	{
		int sum=0,cnt=0;
		for(int j=mp[i];j>=1;j--)
		{
			if(cnt+(i-a[j])<=m)
			{
				sum++;
				cnt+=(i-a[j]);
			}
		}
		ans=max(ans,sum);
	}
	cout<<ans;
	return 0;
}
//snxwlfh  