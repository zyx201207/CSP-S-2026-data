#include <bits/stdc++.h>
#define ll unsigned long long
using namespace std;
const int N=2e6+5;
int c,t,n;
ll d;
ll a[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) 
			cin>>a[i];
		ll k1=d/a[1];
		ll k2=2*k1-1;
		if(k1<=1) cout<<0<<endl;
		else cout<<n+2-k2<<endl;
	}
	return 0;
}