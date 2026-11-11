#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
struct r{
	int u,v;
}c[114514];
int C,T,n,K,ans;
int f[114514],len[114514];
int siz[114514],dep[114514],fa[114514],son[114514];
int idx,id[114514],rk[114514],top[114514],mxidx[114514],mxdep[114514];
int cnt=1,h[114514],zd[114514],nxt[114514];
void add(int u,int v){
	zd[++cnt]=v,nxt[cnt]=h[u],h[u]=cnt;
	zd[++cnt]=u,nxt[cnt]=h[v],h[v]=cnt;
}
void dfs1(int st){
	siz[st]=1;
	dep[st]=dep[fa[st]]+1;
	for(int i=h[st];i;i=nxt[i]){
		int v=zd[i];
		if(v==fa[st]) continue;
		fa[v]=st;
		dfs1(v); 
		if(siz[v]>siz[son[st]]) son[st]=v;
		siz[st]+=siz[v];
	}
}
void dfs2(int st,int t){
	id[st]=++idx;
	rk[idx]=st;
	top[st]=t;
	mxidx[t]=max(mxidx[t],id[st]);
	mxdep[t]=max(mxdep[t],dep[st]);
	if(son[st]) dfs2(son[st],t);
	for(int i=h[st];i;i=nxt[i]){
		int v=zd[i];
		if(v==fa[st] or v==son[st]) continue;
		dfs2(v,v);
	}
}
int check(int l,int r,int root){
	while(l<r){
		int mid=(l+r)/2+1;
		if(siz[rk[mid]]*2>siz[rk[root]]) l=mid;
		else r=mid-1;
	}
	return rk[l];
}
void dfs3(int st,int fa,int id){
	len[st]=0;
	for(int i=h[st];i;i=nxt[i]){
		int v=zd[i];
		if(st==c[id].u and v==c[id].v) continue;
		if(v==c[id].u and st==c[id].v) continue;
		if(v==fa) continue;
		dfs3(v,st,id);
		len[st]=max(len[st],len[v]+1);
	}
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout); 
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>C>>T;
	while(T--){
		ans=1e11;
		cin>>n>>K;
		for(int i=1;i<n;i++){
			cin>>c[i].u>>c[i].v;
			add(c[i].u,c[i].v);
		}
		dfs1(1);
		dfs2(1,1);
		for(int i=1,x,y;i<n;i++){
			if(dep[c[i].u]>dep[c[i].v]) swap(c[i].u,c[i].v);
			siz[1]-=siz[c[i].v];
			if(top[c[i].v]==1) x=check(id[1],id[fa[c[i].v]],1);
			else x=check(id[1],mxidx[1],1);
			y=check(id[c[i].v],mxidx[top[c[i].v]],c[i].v);
			siz[1]+=siz[c[i].v];
//			cout<<x<<" "<<y<<endl;
			int mx=0;
			for(int j=h[x];j;j=nxt[j]){
				int v=zd[j],w;
				if(x==c[i].u and v==c[i].v) continue;
				if(v==c[i].u and x==c[i].v) continue;
				dfs3(v,x,i);
				mx=max(mx,len[v]+1);
				f[len[v]+1]++;
			}
			for(int j=h[y];j;j=nxt[j]){
				int v=zd[j],w;
				if(y==c[i].u and v==c[i].v) continue;
				if(v==c[i].u and y==c[i].v) continue;
				dfs3(v,y,i);
				mx=max(mx,len[v]+1);
				f[len[v]+1]++;
			}
//			cout<<mx<<endl;
//			for(int j=1;j<=mx;j++) cout<<f[j]<<" ";
//			cout<<endl;
			int t=K-2;
			for(int j=mx;j>=1;j--){
				if(t>=f[j]){
					f[j-1]+=f[j];
					t-=f[j],mx--;
				}
				f[j]=0;
			}
			ans=min(ans,mx);
//			cout<<ans<<" ";
		}
		int x=check(id[1],mxidx[1],1),mx=0;
//		cout<<x<<endl;
		for(int j=h[x];j;j=nxt[j]){
			int v=zd[j],w;
			dfs3(v,x,0);
			mx=max(mx,len[v]+1);
			f[len[v]+1]++;
		}
//		cout<<mx<<endl;
//		for(int j=1;j<=mx;j++) cout<<f[j]<<" ";
//		cout<<endl;
		int t=K-1;
		for(int j=mx;j>=1;j--){
			if(t>=f[j]){
				f[j-1]+=f[j];
				t-=f[j],mx--;
			}
			f[j]=0;
		}
		ans=min(ans,mx);
		cout<<ans<<endl;
		cnt=1;
		for(int i=1;i<=n;i++){
			h[i]=0;
			f[i]=0;
			siz[i]=dep[i]=fa[i]=son[i]=0;
			id[i]=rk[i]=top[i]=mxidx[i]=mxdep[i]=0;
		}
	}
	return 0;
}
//1 1
//
//10 3
//1 2
//1 3
//2 4
//2 5
//3 6
//3 7
//3 8
//7 9
//9 10
