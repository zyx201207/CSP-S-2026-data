#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,hd[2000005],ct,to[2000005],nx[2000005],f[1000005][21],dep[1000005],edg[1000005][2],ff[1000005];
void add(int u,int v){
	to[++ct]=v;
	nx[ct]=hd[u];
	hd[u]=ct;
}
void build(int fa,int rt){
	dep[rt]=dep[fa]+1;
	f[rt][0]=fa;
	for(int i=1;i<=20;i++) f[rt][i]=f[f[rt][i-1]][i-1];
	for(int i=hd[rt];i;i=nx[i]){
		if(to[i]!=fa) build(rt,to[i]);
	}
}
int lca(int x,int y){
	if(dep[x]>dep[y]) swap(x,y);
	for(int i=20;i>=0;i--){
		if(dep[f[y][i]]>=dep[x]) y=f[y][i];
	}
	if(x==y) return x;
	for(int i=20;i>=0;i--){
		if(f[x][i]!=f[y][i]){
			x=f[x][i];
			y=f[y][i];
		}
	}
	return f[x][0];
}
int dis(int x,int y){
	int w=lca(x,y);
	return dep[x]+dep[y]-2*dep[w];
}
int cnt(int stt){
	int anss=0;
	while(stt){
		stt=(stt&(stt-1));
		anss++;
	}
	return anss;
}
int find(int x){
	if(x==ff[x]) return x;
	return ff[x]=find(ff[x]);
}
int merge(int x,int y){
	x=find(x);
	y=find(y);
	if(x==y) return 0;
	ff[x]=y;
	return 1;
}
bool check(int stt){
	for(int i=1;i<=n;i++) ff[i]=i;
	int kk=k;
	for(int i=1;i<n;i++){
		int u=edg[i][0],v=edg[i][1];
		if(((stt>>(u-1))&1)&&((stt>>(v-1))&1)) kk-=merge(u,v);
	}
	if(kk<=2) return 1;
	return 0;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	while(cin>>c){
		cin>>t;
		while(t--){
			ct=0;
			memset(hd,0,sizeof hd);
			memset(nx,0,sizeof nx);
			memset(to,0,sizeof to);
			memset(dep,0,sizeof dep);
			cin>>n>>k;
			for(int i=1;i<n;i++){
				cin>>edg[i][0]>>edg[i][1];
				add(edg[i][0],edg[i][1]);
				add(edg[i][1],edg[i][0]);
			}
			build(0,1);
			int anns=1e9+7;
			for(int st=0;st<(1<<n);st++){
				if(cnt(st)!=k) continue;
				if(!check(st)) continue;
				int mx=0;
				for(int i=1;i<=n;i++){
					if((st>>(i-1))&1) continue;
					int mn=1e9+7;
					for(int j=1;j<=n;j++){
						if(((st>>(j-1))&1)&&(i!=j)) mn=min(mn,dis(i,j));
					}
					mx=max(mx,mn);
				}
				anns=min(anns,mx);
			}
			cout<<anns<<"\n";
		}
	}
    return 0;
}
