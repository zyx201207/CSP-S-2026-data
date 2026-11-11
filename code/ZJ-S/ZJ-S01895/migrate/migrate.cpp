#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll t,c,n,d,a[2001000];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		ll x=a[2]-a[1],y=0;
		if(d<2*x||d>=x*(n)){
			cout<<0<<"\n";
			continue;
		}
		x=d/x;
		x=2*x-1;
		cout<<max(n-x,y)<<"\n";
	}
	return 0;
}
