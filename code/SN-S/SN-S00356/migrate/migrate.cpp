// 管晨清 陕西省西安爱知中学 SN-S00356 
#include<bits/stdc++.h>
#define ll int
#define endl '\n'
#define pr pair<ll,ll>
#define fr first 
#define sec second 
using namespace std;
const ll N=5000+10;
ll c,T;
ll n,d;
ll x[N];
ll pre[N];
ll d1[N][N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		if(n==1) cout<<0<<endl;
		else{
			for(ll i=1;i<=n;++i){
				cin>>x[i];
				if(x[i]-x[i-1]>d) {
					cout<<0<<endl;
					n=0;
					break;
				}
				//pre[i]=pre[i-1]+x[i];
			}
			for(ll i=1;i<=n;++i){
				d1[i][i]=0;
				for(ll j=i;j<=n;++j){
					ll a=lower_bound(x+1,x+n+1,x[j]+d)-x-1;
					for(ll k=j;k<=a;++k){
						d1[i][j]=d1[i][j]+1;
					}
					//cout<<d1[i][j]<<endl;
				}
			}
			ll ans=0;
			for(ll i=1;i<=n;++i){
				for(ll j=i+1;j<=n;++j){
					if(i==j) continue;
					else if(d1[i][j]!=j-i+1) ++ans;
				}
			}
			cout<<ans;
		}
	}
	return 0;
} 
