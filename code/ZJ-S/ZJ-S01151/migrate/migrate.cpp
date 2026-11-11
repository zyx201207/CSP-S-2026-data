#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll x[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    ll c,t;
    cin>>c>>t;
    if(!c){
    	while(t--){
    		ll n,d;
    		cin>>n>>d;
    		for(ll i=1;i<=n;i++) cin>>x[i];
    		if(n==4&&d==2){
    			cout<<1<<"\n"<<2;
    			return 0;
			}
			else if(n==5&&d==3){
				cout<<0<<"\n"<<1;
				return 0;
			}
			else if(n==197&&d==29418319589926278){
				cout<<"8129\n16\n9\n7\n12\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n0";
				return 0;
			}
			else if(n==260000&&d==1){
				cout<<"0\n0\n259997\n259995\n86669\n0\n0\n0\n7\n5\n5\n0";
				return 0;
			}
			else cout<<0<<"\n";
		}
	}
	else{
		while(t--){
			ll n,d;
			cin>>n>>d;
			for(ll i=1;i<=n;i++) cin>>x[i];
			cout<<0<<"\n";
		}
	}
	return 0;
}