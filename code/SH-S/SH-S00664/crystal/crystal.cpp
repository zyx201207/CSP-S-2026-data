#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[500005],ans;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	ll l=1,tot=0;
	for(ll r=1;r<=n;r++){
		tot+=(a[r]-a[r-1])*(r-l);
		while(tot>m){
			tot-=a[r]-a[l];
			l++;
		}
		ans=max(ans,r-l+1);
	}
	cout<<ans;
	return 0;
}
