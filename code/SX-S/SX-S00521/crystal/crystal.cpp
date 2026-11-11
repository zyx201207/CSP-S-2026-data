#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[600005],n,m,sum,su[600006];
bool che(int gs){
	int mn=LLONG_MAX;
	for(int i=gs;i<=n;i++){
		mn=min(mn,abs(gs*a[i]-(su[i]-su[i-gs])));
	}
	return mn<=m;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		su[i]=su[i-1]+a[i];
	}
	int l=1,r=n;
	int ans;
	while(l<=r){
		int md=(l+r)/2;
		if(che(md)){
			ans=md;
			l=md+1;
		}
		else{
			r=md-1;
		}
	}
	cout<<ans;
	return 0;
}