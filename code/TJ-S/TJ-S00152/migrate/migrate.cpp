#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,t,n,d,x[310],maxx[310];
ll mindis[310][310],cntmin[310][310];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(ll i=1;i<=n;i++)cin>>x[i];
		ll a=1;
		for(ll i=1;i<=n;i++){
			while(x[a]-x[i]<=d&&a<=n) a++;
			maxx[i]=a-1;
		}
		memset(mindis,0x3f3f3f3f3f3f3f3f,sizeof(mindis));
		memset(cntmin,0x3f3f3f3f3f3f3f3f,sizeof(cntmin));
		for(ll i=1;i<n;i++){
			for(ll j=i+1;j<=maxx[i];j++){
				mindis[i][j]=1;
				cntmin[i][j]=1;
			}
		}
		ll ans=0;
		for(ll dx=2;dx<n;dx++){
			for(ll i=1;i+dx<=n;i++){
				if(mindis[i][i+dx]!=1) for(ll j=i+1;j<i+dx;j++){
					ll nd=mindis[i][j]+mindis[j][i+dx];
					ll ncnt=cntmin[i][j]*cntmin[j][i+dx];
					ncnt=min(ncnt,20000ll);
					if(mindis[i][i+dx]>nd){
						mindis[i][i+dx]=nd;
						cntmin[i][i+dx]=ncnt;
					}
					else if(mindis[i][i+dx]==nd){
						cntmin[i][i+dx]+=ncnt;
					}
					
				}
			}
		}
		for(ll i=1;i<n;i++)
			for(ll j=i+1;j<=n;j++)
				if(cntmin[i][j]==2) ans++;
		cout<<ans<<'\n'; 
	}
    return 0;
}

