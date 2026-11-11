//14:34
#include<bits/stdc++.h>
using namespace std;
#define re register
#define ll long long
#define forl(i,a,b) for(re ll i=a;i<=b;i++)
#define forr(i,a,b) for(re ll i=a;i>=b;i--)
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define pb push_back
#define x first
#define y second
ll n,m,ans;
ll a[500010];
ll pre[500010];
ll chk(ll l,ll r){
	return a[r]*(r-l+1)-(pre[r]-pre[l-1]);
}
void Solve(){
	cin>>n>>m;
	forl(i,1,n) cin>>a[i];
	sort(a+1,a+1+n);
	forl(i,1,n) pre[i]=pre[i-1]+a[i];
	forl(i,1,n){
		ll L=1,R=i;
		while(L<R){
			ll Mid=(L+R)/2;
			if(chk(Mid,i)<=m) R=Mid;
			else L=Mid+1;
		}
		ans=max(ans,i-L+1);
	}
	cout<<ans<<endl;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	IOS;
	ll t=1;
//	cin>>t;
	while(t--) Solve();
	return 0;
}
