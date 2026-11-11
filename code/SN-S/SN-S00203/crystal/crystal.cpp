#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N=5e5+5;
const int mod=1e9+7;

ll n,m,k;
ll a[N];

bool check(ll x){
	bool ok=false;
	for(int i=1;i<=n;i++){
		if(a[i+1]-a[i]>m)continue;
		ll sum=0;
		for(int j=1;j<x;j++){
			if(sum>m){
				break;
			}
			sum+=a[x]-a[j];
		}
		if(sum<=m){
			ok=true;
			return ok;
		}
	}
	return ok;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	bool h=true;
	for(int i=1;i<=n;i++){
		if(a[i+1]-a[i]<=m){
			h=false;break;
		}
	}
	if(h){
		cout<<1<<'\n';
		return 0;
	}
	sort(a+1,a+n+1);
	ll l=1,r=n;
	while(l<r){
		ll mid=(l+r+1)/2;
		if(check(mid)){
			l=mid;
		}else{
			r=mid-1;
		}
	}
	cout<<l<<'\n';
	return 0;
}
