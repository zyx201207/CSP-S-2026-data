#include<bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define double long double
#define endl '\n'
#define pb push_back
#define now_time (1e3*clock()/CLOCKS_PER_SEC)
using namespace std;
const int inf=LLONG_MAX>>1;
int n,m,a[500005],s[500005],ans;
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		s[i]=s[i-1]+a[i];
	for(int i=1;i<=n;i++)
	{
		int l=0,r=i+1;
		while(l+1<r)
		{
			int mid=l+r>>1;
			if(a[i]*(i-mid+1)-s[i]+s[mid-1]>m)l=mid;
			else r=mid;
		}
		ans=max(ans,i-l);
	}
	cout<<ans;
	return 0;
}
