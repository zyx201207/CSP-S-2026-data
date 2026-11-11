#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+15; 
int n,m;
int a[N];
vector<int> e[50];
int mp[N];
int ans;
int cnt=1;
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	// gan jue zhe ti shi yi yan ti
	// 9:45 correct solution 100 pts
	// 9:56 finish coding 
	// 10:07 finish debugging
	// so easy!!!!!nice!!!!!
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=31;j++)
		{
			if((a[i]>>j)&1)
			{
				e[j].push_back(i);
			}
		}
	}
	int lst=-1;
	for(int j=31;j>=0;j--)
	{
		if((int)e[j].size()<m) continue;
		if(lst==-1)
		{
			ans+=(1ll<<j);
			lst=j;
			for(int i=0;i<e[lst].size();i++)
			{
				mp[e[lst][i]]++;
			}
		}
		else
		{
			int tot=0;
			for(int i=0;i<e[j].size();i++)
			{
				mp[e[j][i]]++;
				if(mp[e[j][i]]==cnt+1) tot++;
			}
			if(tot>=m)
			{
				lst=j;
				cnt++;
				ans+=(1ll<<j);
			}
		}
	}
	cout<<ans<<endl;
}
