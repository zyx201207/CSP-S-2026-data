#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e6+10,M=5e2+10;
ll n,m,k,ans;
ll a[N],b[N];
void solve(){
	cin>>n>>k;
	for(ll i=1;i<n;i++) cin>>a[i]>>b[i];
	cout<<k/2<<"\n";
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>m>>m;
	while(m--){
		solve();
	}
	return 0;
}
/*
0 2 5 20 2 
4 1 9 2 5 
3 1 5 2 7 4 6 
3 2 3 3 4 5 7 
1 3 
1 2 

*/
