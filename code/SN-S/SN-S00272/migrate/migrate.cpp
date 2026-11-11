#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,T;
int n,d,ans;
int a[2000100];
int pre[2000100];
int di[2000100];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--)
	{
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			di[i]=0;
		}
		for(int i=1;i<n;i++)
		{
			auto r=upper_bound(a+i,a+n+1,a[i]+d);
			r--;
			int x=r-a-i;
			di[i]++;di[i+x+1]--;
		}
		for(int i=1;i<=n;i++) pre[i]=pre[i-1]+di[i];
		for(int i=1;i<=n;i++)
			if(pre[i]==3) ans++;
		cout<<ans<<'\n';
	}
}
