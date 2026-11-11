#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define F first
#define S second
#define mkp make_pair
#define psb push_back
const int N=1e6+1000;
const int inf=1e17;
int c,T,n,k;
vector<int>e[N];
int limx,limy,nlim;
int unok(int x,int y){
	return limx==min(x,y)&&limy==max(x,y);
}
int sz[N];
void gtsz(int x,int fa){
	sz[x]=1;
	for(int y:e[x]){
		if(y==fa||unok(x,y)) continue;
		gtsz(y,x);sz[x]+=sz[y];
	}
}
int dep[N],alsz,nminn,nmini;
void gtroot(int x,int fa){
	int maxx=alsz-sz[x];
	for(int y:e[x]){
		if(y==fa||unok(x,y)) continue;
		gtroot(y,x);maxx=max(maxx,sz[y]);
	}if(maxx<nminn) nminn=maxx,nmini=x;
}
void dfs2(int x,int fa){
	dep[x]=0;
	for(int y:e[x]){
		if(y==fa||unok(x,y)) continue;
		dfs2(y,x);
		dep[x]=max(dep[x],dep[y]+1);
	}
}
int solve(int w){
	gtsz(w,0);nminn=inf,nmini=0;
	alsz=sz[w];
	gtroot(w,0);
	
	int rt=nmini;
	dfs2(rt,0);
	queue<int>q;
	q.push(rt);
	int cnt=0;
	while(!q.empty()){
		cnt++;
		int x=q.front();q.pop();
		for(int y:e[x]){
			if(dep[y]>dep[x]||unok(x,y)) continue;
			if(dep[y]+1>nlim) q.push(y);
		}
	}
	return cnt;
}
int chk(int lim){
	nlim=lim;
	int minn=n;
	for(int x=1;x<=n;x++){
		for(int y:e[x]){
			if(y<x) continue;
			limx=x;limy=y;
			minn=min(minn,solve(x)+solve(y));
		}
	}limx=0;
	minn=min(minn,solve(1));
	return minn<=k;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
//	system("fc hub5.ans hub.out");return 0;
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int u,v;cin>>u>>v;
			e[u].psb(v);e[v].psb(u);
		}
		if(c==13||c==14){
			if(k==n) cout<<"0\n";
			else{
				int tms=(n-5)/2;
				if(k-1>tms) cout<<"1\n";
				else{
					int maxt=(tms+3)/4+1,mtms=(tms%4==0?4:tms%4);
					if(k-1<=mtms) cout<<maxt<<"\n";
					else{
						k-=mtms;maxt--;
						while(k>4){
							k-=4;maxt--;
						}cout<<maxt<<"\n";
					}
				}
			}for(int i=1;i<=n;i++) e[i].clear();
			continue;
		}
		int l=0,r=n-1;
		while(l<r){
			int mid=((l+r)>>1);
			if(chk(mid)) r=mid;
			else l=mid+1;
		}cout<<l<<"\n";
		
		for(int i=1;i<=n;i++){
			e[i].clear();
		}
	}
	return 0;
}
/*
*/
