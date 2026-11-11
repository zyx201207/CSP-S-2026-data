#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5005;
const ll INF=1e18;
struct Queue{
	ll x,wz;
}q[N];
ll ans,c,T,n,d,hd,tl,dis[N],wz[N],g[N],f[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	//LL!
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>wz[i];
		ans=0;
		for(int i=1;i<=n;i++){
			for(int j=0;j<=n;j++) dis[j]=f[j]=g[j]=0;
			hd=1;tl=0;
			for(int j=i;j<=n;j++){
				while(hd<=tl&&q[hd].wz<wz[j]-d) hd++;
				if(j!=i){
					if(hd<=tl) dis[j]=q[hd].x+1;
					else dis[j]=INF;
				}
				q[++tl]=Queue{dis[j],wz[j]};
			}
			g[i]=1;f[0]=1;
			for(int j=i+1,k=i;j<=n;j++){
				while(k<=j&&wz[k]<wz[j]-d){
					if(dis[k]<INF) f[dis[k]]-=g[k];
					k++;
				}
				if(dis[j]<INF) g[j]+=f[dis[j]-1],f[dis[j]]+=g[j];
			}
			for(int j=i;j<=n;j++)
				ans+=(g[j]==2);
		}
		cout<<ans<<"\n";
	}
	return 0;
}
