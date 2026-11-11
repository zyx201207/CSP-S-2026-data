#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=2e5+10;
struct node{
	ll num;
	string s;
}a[N]; 
ll n,ans=0;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++) cin>>a[i].num>>a[i].s;
	ll l=1,r=n;
	while(1){
		if(l==r) break;
		if(a[l].num==0){l++;continue;}
		if(a[r].num==0){r--;continue;}
		if(a[l].s==a[r].s){
			ll now=min(a[l].num,a[r].num);
			a[l].num-=now;
			a[r].num-=now;
			continue;
		}
		if(a[l].s!=a[r].s){
			ll now=min(a[l].num,a[r].num);
			a[l].num-=now;
			a[r].num-=now;
			ans+=now;
			continue;
		}
	}
	cout<<ans<<'\n';
	return 0;
}
