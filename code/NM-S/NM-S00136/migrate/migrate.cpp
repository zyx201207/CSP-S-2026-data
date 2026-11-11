#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int nn=2e6+6;
ll x[nn],ans,t,c;
int main(){
	freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>c>>t;
    while(t--){
    	ll n,d;
    	cin>>n>>d;
    	memset(x,0,sizeof(x));
    	for(int i=1;i<=n;i++){
    		cin>>x[i];
		}
		ll cha=x[2]-x[1];
		if(cha>d){
			cout<<0;
			continue;}
		if(cha*2>d){
			cout<<0;
			continue;
		}
		for(int i=1;i<=n;i++){
			if(i+3<=n){
				ans++;
			}
				cout<<ans<<endl;
		ans=0;
		}
	}
	return 0;}
