#include <bits/stdc++.h>
using namespace std;
#define ll long long int
const int maxn=5e5+10;
ll a[maxn],n,m,ans=1;
unsigned ll pre[maxn],cnt;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(unsigned ll i=2;i<=n;i++){
		pre[i]=pre[i-1]+(i-1)*(a[i]-a[i-1]);
	}
	for(unsigned ll i=1;i<=n;i++){
		int l=1,r=i;
		while(l<=r){
			unsigned ll mid=(r-l)/2+l;
			cnt=(a[i]-a[mid-1]);
			if(pre[i]-pre[mid-1]-(mid-1)*cnt<=m){
				if(i-mid+1>ans)ans=i-mid+1;
				r=mid-1;
			}
			else l=mid+1;
		}
	}
	cout<<ans;
	return 0;
}
