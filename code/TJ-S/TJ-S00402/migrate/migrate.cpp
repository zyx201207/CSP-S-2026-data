#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll c,t,n,d,a[2000004];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(ll i=1;i<=t;i++){
		cin>>n>>d;
		if(n<=2){
			cout<<0<<endl;
			continue;
		}
		memset(a,0,sizeof(a));
		for(ll j=1;j<=n;j++){
			cin>>a[j];
		}
		ll cz=abs(a[2]-a[1]);
		d/=cz;
		if(d<=1){
			cout<<0<<endl;
			continue;
		}
		d=d*2-1;
		cout<<max(0ll,n-d)<<endl;
	}
}
