#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
struct node{
	char ch='a';
	ll cnt=0;
};

void solve(){
	ll n;cin>>n;
	vector<ll> a(n+1);
	vector<char> c(n+1);
	for(int i=1;i<=n;i++) cin>>a[i]>>c[i];
	node pre={c[1],a[1]},nxt={c[n],a[n]};
	ll l=1,r=n,ans=0;
	while(l<r){
		if(pre.ch!=nxt.ch) ans+=min(pre.cnt,nxt.cnt);
		ll mn=min(pre.cnt,nxt.cnt);
		pre.cnt-=mn;
		nxt.cnt-=mn;
		if(pre.cnt==0){
			l++;
			pre={c[l],a[l]};
		}
		if(nxt.cnt==0){
			r--;
			nxt={c[r],a[r]};
		}
	}
	cout<<ans;
	return;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	solve();
	return 0;
}
