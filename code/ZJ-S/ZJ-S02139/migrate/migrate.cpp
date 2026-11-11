#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;
typedef long long ll;

inline ll readl(){
	ll x=0,y=1;char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') y=-y;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<3)+(x<<1)+(c-'0');
		c=getchar();
	}
	return x*y;
}

void writel(ll x){
	if(x<0) putchar('-'),x=-x;
	if(x<10) putchar(x+'0');
	else writel(x/10),putchar(x%10+'0');
}
ll n,d;
const ll N=2e6+10;
ll x[N],nxt[N],cnt[N],dis[N];
queue<ll> q;
void BFS(ll u){
	
	while(!q.empty()) q.pop();
	q.push(u);dis[u]=0;cnt[u]=1;
	while(!q.empty()){
		ll i=q.front();q.pop();
		if(nxt[i]==-1||i==n)continue;
		for(ll j=nxt[i];j>i;j--){
			if(dis[j]==n+1||dis[j]==dis[i]+1){
				if(dis[j]==n+1)q.push(j);
				cnt[j]+=cnt[i];
				dis[j]=dis[i]+1;
			}
		}
	}
}
void sol(){
	for(ll i=1;i<=n;i++){
		if(x[n]-x[i]<=d)
			nxt[i]=n;
		else{
			nxt[i]=upper_bound(x+i,x+n+1,x[i]+d)-x-1;
			if(nxt[i]==i)
				nxt[i]=-1;
		}
//		cerr<<nxt[i]<<',';
	}
//	cerr<<'\n';
	ll ans=0;
	for(ll i=1;i<n;i++){
		for(ll j=i;j<=n;j++) cnt[j]=0,dis[j]=n+1;
		BFS(i);
		for(ll j=i;j<=n;j++){
		 ans+=(cnt[j]==2);
		//		cerr<<j<<':'<<dis[j]<<','<<cnt[j]<<'\n';
		}
	}
	writel(ans);putchar('\n');
}
ll cas,T;
void do_sth(){
	while(T--){
		n=readl(),d=readl();
		for(ll i=1;i<=n;i++)
			x[i]=readl();
		if(x[n]-x[1]<=d) {puts("0");continue;}
		ll R_bound=x[1]+d,L_bound=x[n]-d;
		ll lp=-1,rp=-1;
		for(ll i=1;i<=n;i++){
			if(lp==-1&&x[i]>=L_bound) lp=i;
			if(x[i]<=R_bound) rp=i;
		}
		ll v=rp;
		for(ll i=1;i<=n;i++){
			if(v==n) nxt[i]=v;
			else{
				while(v<n&&x[i]+d>=x[v+1]) v++;
				nxt[i]=v;
			}
		}
		ll ans=0;
		for(ll i=1;i<lp;i++){
			ll rrr=nxt[i];//rrr>=rp
			if(rrr>=lp+2) continue;
			if(rrr==lp+1){
				ans+=n-nxt[lp-1];
			}else{
				if(lp>2){
					ans+=nxt[lp-1]-nxt[lp-2];
				}else{
					ans+=0;
				}
			}
		}
		writel(ans);puts("");
	}	
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cas=readl(),T=readl();
	if(cas==13||cas==14){
		do_sth();
		fclose(stdin);
		fclose(stdout);
		return 0;		
	}
	while(T--){
		n=readl(),d=readl();
		for(ll i=1;i<=n;i++)
			x[i]=readl();
		sol();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
