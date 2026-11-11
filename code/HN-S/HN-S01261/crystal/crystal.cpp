#include<bits/stdc++.h>
#define ll long long
#define db double
#define endl '\n'
#define Max(a,b,c) max(a,max(b,c))
#define Min(a,b,c) min(a,min(b,c))
#define fi first
#define se second
using namespace std;
const int N=5e5+7;
const int mod=998244353;
const int INF=1e9+7;
ll a[N],b[N];
/*
线段树4倍，数组清空，注意longlong,优先暴力 
while(1) rp++;不犯糖 
*/
void solve(){
	int n;
	ll m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) b[i]=a[i]+b[i-1];
	ll ans=1;
	for(int i=1;i<=n;i++){
		ll l=1,lst=i/2+i%1;
		while(lst&&l>0){
			if((i-l+1)*a[i]-(b[i]-b[l-1])<=m){
			    ans=max(ans,i-l+1);
				//if(ans==4) cout<<l<<" "<<i<<" "<<lst<<endl;
				l-=lst;
				lst=lst/2+lst%1;
			}else{
				l+=lst;
				lst=lst/2+lst%1;
			}
		}
	}
	cout<<ans<<endl;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	/*
	int T;
	cin>>T;
	while(T--)*/
	    solve();
	return 0;
}//Oct31==Dec25?
/*
5 5
1 2 4 8 9
5 8
-3 -1 2 2 7
*/
