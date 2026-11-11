#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=5e5+5;
ll n,m,a[maxn],ans;
namespace Sub{
	bool check(){
		for(int i=1;i<=n;i++){
			if(a[i]!=i) return 0;
		}
		return 1;
	}
	int solve(){
		ll l=1,r=m,res=0;
		while(l<=r){
			ll mid=(l+r)/2;
			if(mid*(mid-1)<=2*m) res=mid,l=mid+1;
			else r=mid-1;
		}
		return res;
	}
	void main(){
		ll k=a[2]-a[1],x=solve();
		cout<<min(n,x);
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	if(Sub::check()){Sub::main();return 0;}
	for(int k=1;k<=n;k++){
		ll res=0,t=m;
		vector<ll>v;
		for(int i=1;i<=k;i++) v.push_back(a[k]-a[i]);
		sort(v.begin(),v.end());
		for(ll x:v){
			if(t>=x) t-=x,res++;
			else break;
		}
		cerr<<res<<' '<<k<<'\n';
		ans=max(ans,res);
	}
	cout<<ans;
	return 0;
}
/*
By ZJ-S00382.
Luogu UID:1086453.
*/