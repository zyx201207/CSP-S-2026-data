#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define fi first
#define se second
#define mk make_pair
const int siz=1e6+10;
int a[siz];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0),cout.tie(0);
	ios::sync_with_stdio(false);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	int shu=1,ss=0,ans=1;
	for(int i=2;i<=n;i++)
	{
		ss+=(a[i]-a[i-1])*(i-shu);
		while(shu<=i&&ss>m)ss-=a[i]-a[shu],shu++;
		ans=max(ans,i-shu+1);
	}
	cout<<ans<<'\n';
	return 0;
}
//@@@@@@@@@@@