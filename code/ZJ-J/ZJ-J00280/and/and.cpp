#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e6+10;
ll n,m,k,ans;
ll a[N];
struct node{
	ll idx,sum;
	bool operator<(const node &o)const{
		return sum>o.sum;
	}
}b[N];
void solve(){
	cin>>n>>m;
	for(ll i=1;i<=n;i++) cin>>a[i];
	for(ll j=32;j>=0;j--){
		for(ll i=1;i<=n;i++) b[i].sum=((a[i]>>j)&1),b[i].idx=i;
		sort(b+1,b+1+n);
		if(b[m].sum==1){
			ans+=(1<<j);
			for(ll i=n;i>=1&&b[i].sum==0;i--) a[b[i].idx]=0;
		}
//		for(ll i=n;i>=1&&b[i].sum==0;i--) a[b[i].idx]=0;
	}
	cout<<ans<<"\n";
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	solve();
	return 0;
}
/*
4 2
3 15 12 12
0011 1111 1100 1100

5 2
31 3 1 15 7

11111 00011 00001 01111 00111

111
111
101
011
001
*/
