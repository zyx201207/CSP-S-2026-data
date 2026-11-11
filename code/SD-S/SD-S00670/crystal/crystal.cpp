#include<bits/stdc++.h>
#define FAST ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define READ_IN_FILE
#define int long long
using namespace std;
const int N=5e5+10,P=998244353;
int n,m,a[N],sum,ans; 
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int r=1,l=1;r<=n;r++)
	{
		sum+=a[r];
		while(l<=r&&a[r]*(r-l+1)-sum>m)sum-=a[l],l++; 
		ans=max(ans,r-l+1);
	}
	cout<<ans;
	return;
}
signed main()
{
	FAST
#ifdef READ_IN_FILE
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
#endif
	int _T_=1;
#ifdef MSOD
	cin>>_T_;
#endif
	while(_T_--)solve();
	return 0;
}
