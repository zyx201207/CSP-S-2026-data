#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1e6+7;
int n,m,a[maxn],pre[maxn],ans=1,tot,num,rem,jud;
bool fa=1;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	jud=a[2]-a[1];
	for(int i=2;i<=n;i++)if((a[i]-a[i-1])!=jud)fa=0;
	if(fa==1)
	{
		for(int i=1;i<n;i++)pre[i]=i*jud;
		for(int i=1;i<n;i++)
		{
			num+=pre[i];
			if(num>m)
			{
				cout<<i<<endl;
				return 0;
			}
		}
	}
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++)pre[i]=a[i+1]-a[i];
	for(int i=1;i<=n;i++)
	{
		tot=i-1;
		num=pre[tot];
		rem=num;
		while(num<=m&&tot>0)
		{
			ans=max(ans,i-tot+1);
			tot--;
			rem+=pre[tot];
			num+=rem;
		}
	}
	cout<<ans<<endl;
	return 0;
}