#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+5;
ll n,m;
ll a[N],d[N],s[N];
ll cnt=1;
ll ans=0;
bool cmp(ll& x,ll& y){
	return x<y;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	d[1]=0;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1,cmp);
	s[1]=a[1];
	for(int i=2;i<=n;i++){
		d[i]=abs(a[i]-a[i-1]);
		s[i]=s[i-1]+a[i] ;
	}
	sort(d+2,d+n+1,cmp);
	ll sum=0;
	for(int i=2;i<=n;i++){
		if(s[i]==a[i+1]){
			continue;
		}
		sum+=d[i];
		if(sum>m){
			break;
		}
		ans++;
	}cout<<ans;
	return 0;
}
