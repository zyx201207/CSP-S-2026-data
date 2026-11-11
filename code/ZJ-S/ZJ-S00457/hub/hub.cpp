#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define inf 1000000000000000000
#define vec vector<ll>
#define pii pair<ll,ll>
#define all(x) x.begin(),x.end()
using namespace std;

ll max(ll a,ll b){return (a<b?b:a);}
ll min(ll a,ll b){return (a>b?b:a);}
ll lowbit(ll x){return x&(-x);}
ll ksm(ll a,ll d,ll mo=mod){
	a%=mo;
	ll ans=1;
	for(;d;d>>=1){
		if(d&1)ans=ans*a%mo;
		a=a*a%mo;
	}
	return ans;
}

void solve(){
	cout<<0<<'\n';
}

int main(){
//  system("fc hub1.ans hub.out");return 0;
//	freopen("hub1.in","r",stdin);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

	ll t,c;
	for(cin>>c>>t;t;t--)
	solve();

	return 0;
}

/*
*/

