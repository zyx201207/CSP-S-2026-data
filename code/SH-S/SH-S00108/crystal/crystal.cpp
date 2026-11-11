#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
typedef double db;
const ll N=5e5+9,INF=0x3f3f3f3f;
ll n,m,t,a[N],s[N];
bool chk(ll d){
	for(ll i=1;i<=n-d+1;i++){
		t=d*a[i+d-1]-(s[i+d-1]-s[i-1]);
		if(t<=m) return 1;
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(ll i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	ll l=1,r=N,mid,ans=1;
	while(l<=r){
		mid=l+(r-l)/2;
		if(chk(mid)){ans=mid; l=mid+1;}
		else r=mid-1;
	}
	cout<<ans<<endl;
	return 0;
}
//g100
