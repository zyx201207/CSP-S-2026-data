#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=5005,INF=1e18+5;
ll c,t,a[N],mind[N][2];
inline ll read(){
	ll xx=0,sta=1;char cc=getchar();
	while(cc<'0'||cc>'9'){if(cc=='-')sta=-1;cc=getchar();}
	while(cc>='0'&&cc<='9'){xx=xx*10+cc-'0';cc=getchar();}
	return xx*sta;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read();t=read();
	while(t--){
		ll n=read(),d=read(),cnt=0;
		for(ll i=1;i<=n;i++) a[i]=read();
		for(ll i=2;i<=n;i++){
			mind[i][0]=INF;
			mind[i][1]=0;
		}
		for(ll l=1;l<n;l++){
			mind[l][0]=0;mind[l][1]=1;
			for(ll r=l+1;r<=n;r++){
				for(ll i=l;i<=r-1;i++){
					if(mind[i][0]+1<mind[r][0]){
						mind[r][0]=mind[i][0]+1;
						mind[r][1]=mind[i][1];
					}else if(mind[i][0]+1==mind[r][0]) mind[r][1]+=mind[i][1];
				}
				if(mind[r][1]==2) cnt++;
			}	
		}
		printf("%lld\n",cnt);
	}
	return 0;
}

