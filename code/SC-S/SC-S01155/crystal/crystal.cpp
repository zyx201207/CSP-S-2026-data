//CSP-S 2026 A by wyyinput
//Task name: crystal
//Date: 2026/10/31
#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define pii pair<int,int>
#define pli pair<ll,int>
#define pil pair<int,ll>
#define pll pair<ll,ll>
#define fi first
#define se second
using namespace std;
const int N=5e5+55;
int n;
ll m;
ll a[N];
ll sum[N];
int ans;
bool check(int lj,int rj){
	ll num=a[rj]*(rj-lj+1)-sum[rj]+sum[lj-1];
	return num<=m;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	for(int i=n;i;i--){
		if(i<ans){
			break;
		}
		int l=1,r=i,mid;
		while(l<=r){
			mid=l+r>>1;
			if(check(mid,i)){
				r=mid-1;
			}else{
				l=mid+1;
			}
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans<<"\n";
	return 0;
}