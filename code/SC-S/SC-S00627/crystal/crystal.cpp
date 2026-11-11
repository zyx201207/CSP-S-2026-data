#include<bits/stdc++.h>
#define ll long long

using namespace std;

ll a[500001];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n,st=1;
	ll m,ne=0;
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	ll ans=1,res=1;
	for(ll i=2;i<=n;i++){
		ll pl=(i-st)*(a[i]-a[i-1]);
		while(ne+pl>m && st<i){
			ne-=a[i-1]-a[st];
			st++;
			res--;
			pl=(i-st)*(a[i]-a[i-1]);
		}
		ne+=pl;
		res++;
		ans=max(ans,res);
	}
	cout<<ans<<endl;
	
	return 0;
}
/*
15:20 :)
*/