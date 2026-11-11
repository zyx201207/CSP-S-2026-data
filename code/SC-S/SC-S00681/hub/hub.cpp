#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,ans=1e9,a[1000006],u[1000006],v[1000006],dep[1000006],bb[1000006];
vector<int> g[1000006];
int cz(int x){
	if(bb[x]==x) return x;
	return bb[x]=cz(bb[x]);
}
void dfs(int x,int f){
	for(int i:g[x]){
		if(i==f) continue;
		dep[i]=min(dep[i],dep[x]+1),dfs(i,x);
	}
}
void sol(int x,int y){
	if(x==n+1){
		for(int i=1;i<=n;i++) bb[i]=i;
		for(int i=1;i<n;i++)
			if(a[u[i]]&&a[v[i]]){
				int xb=cz(u[i]),yb=cz(v[i]);
				if(xb!=yb) bb[yb]=xb;
			}
		int d=0,xx=0,yy=0;
		for(int i=1;i<=n;i++) if(cz(i)==i&&a[i]) d++;
		if(d>2) return;
		for(int i=1;i<=n;i++) if(a[i]) dep[i]=0;
		for(int i=1;i<=n;i++) if(cz(i)==i&&a[i]) if(xx) yy=i;else xx=i;
		dfs(xx,0),dfs(yy,0);
		d=0;
		for(int i=1;i<=n;i++) d=max(d,dep[i]);
		for(int i=1;i<=n;i++) dep[i]=1e9;
		ans=min(ans,d);return;
	}
	sol(x+1,y);
	if(y<k) a[x]=1,sol(x+1,y+1),a[x]=0;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k,ans=1e9;
		if(n<=k){
			cout<<0<<'\n';
			continue;
		}
		for(int i=1;i<=n;i++) g[i].clear(),dep[i]=1e9;
		for(int i=1,x,y;i<n;i++) cin>>x>>y,u[i]=x,v[i]=y,g[x].push_back(y),g[y].push_back(x);
//		if(!c){
//			int z=(n-k)/3;
//			int ys=(n-k)%3;
//			if(!ys) ans=(z+1)/2;
//			else ans=(z+2)/2;
//			cout<<ans<<'\n';
//			continue;
//		}
		sol(1,0),cout<<ans<<'\n';
	}
	return 0;
}