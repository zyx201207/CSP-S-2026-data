#include<bits/stdc++.h>
using namespace std;
#define ll long long


const int N=2e6+5;
ll x[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int q=1;q<=t;++q){
		ll n,d;
		cin>>n>>d;
		for(int i=1;i<=n;++i){
			x[i]=0;
			cin>>x[i];
		}
		ll ans=0;
		for(int i=1;i<=n-3;++i){
			for(int j=i+3;j<=n;++j){
				int now=1;
				int nw=0;
				while(i+now<j-now){
						if(x[j-now]-x[i+now]<=d&&j-now!=i+now&&j-now-i<=d){
						nw++;
					}
					now++;
				}
				if(nw==1){
					ans++;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
