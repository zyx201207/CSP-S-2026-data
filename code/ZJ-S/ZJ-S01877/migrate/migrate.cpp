#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+10;
ll c,t,b[3010][3010],ss,INF=LONG_LONG_MAX;
ll ans,s[3010][3010],a[3010];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--){
		ll n,d;
		cin>>n>>d;
		ans=0;
		memset(b,0,sizeof(b));
		memset(s,0,sizeof(s));
		for(ll i=1;i<=n;i++)cin>>a[i];
		for(ll i=1;i<=n;i++){
			for(ll j=i+1;j<=n;j++){
				if(a[j]-a[i]<=d){
					b[i][j]=1;
					s[i][j]=1;
				}
				else b[i][j]=INF;
			}
		}
		for(ll i=1;i<=n;i++){
			for(ll j=i+1;j<=n;j++){
				for(ll k=i+1;k<j;k++){
					if(b[i][k]!=INF&&b[k][j]!=INF){
						ll t=b[i][k]+b[k][j];
						if(t<b[i][j]){
							b[i][j]=t;
							s[i][j]=s[i][k]*s[k][j];
						}
						else if(t==b[i][j])s[i][j]+=s[i][k]*s[k][j];
					}
				}
				ss=min(ss,b[i][j]);
				if(s[i][j]==2)ans++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
