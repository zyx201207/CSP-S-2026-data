#include<bits/stdc++.h>
using namespace std;
const int N=2e6;
#define ll long long
ll x[N];
ll c,t;
ll f[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		ll ans=0;
		ll n,d;
		cin>>n>>d;
		cin>>x[0];
		for(int i=1;i<n;i++){
			cin>>x[i];
			f[i]=x[i]-x[i-1];
		}
		for(int i=0;i<n-3;i++){
			if(f[i+3]>d){
				i+=3;
			}
			if((x[i+3]-x[i])>d){
				if(x[i+3]-x[i+1]<=d&&x[i+2]-x[i+1]<=d)
				ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

