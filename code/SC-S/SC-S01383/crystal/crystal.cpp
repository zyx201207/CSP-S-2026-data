#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=500005;
const int INF=0x3f3f3f3f;
int n;
ll m,a[N],sum[N];
inline bool check(int st,int ed){
	ll tar=a[ed]*(ed-st+1);
	ll now=sum[ed]-sum[st-1];
	if(tar<now) return false;
	return ((tar-now)<=m);
}
signed main(){
//	freopen("crystal4.in","r",stdin);
//	freopen("my.out","w",stdout);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i)
		cin>>a[i];
	sort(a+1,a+n+1,less<ll>());
	for(int i=1;i<=n;++i)
		sum[i]=sum[i-1]+a[i];
	int ans=0;
	for(int i=1;i<=n;++i){
		int l=1,r=i,mid,res=INF;
		while(l<=r){
			mid=(l+r)>>1;
			if(check(mid,i)){
				res=mid;
				r=mid-1;
			}else l=mid+1;
		}
		ans=max(ans,i-res+1);
	}
	cout<<ans;
}