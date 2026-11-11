#include <bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int vis[maxn],mxdep[maxn],maxx,ss[maxn],tt,lst,ans,now,sum,sz[maxn],cmax[maxn],pre,suf,val1[maxn];
int sid,T,n,m,x,y,rt,dep[maxn],fy,fa[maxn],st[maxn],tp,nxt,fe[maxn],val2[maxn],lun;
vector<int>tu[maxn],f[maxn];
inline void dfs1(int q,int w){
	dep[q]=dep[w]+1;
	if(dep[q]>dep[rt]){
		rt=q;
	}
	for(int i=0;i<tu[q].size();i++){
		if(tu[q][i]!=w){
			dfs1(tu[q][i],q);
		}
	}
	return;
}
inline void dfs2(int q,int w){
	fa[q]=w;
	dep[q]=dep[w]+1;
	if(dep[q]>dep[fy]){
		fy=q;
	}
	for(int i=0;i<tu[q].size();i++){
		if(tu[q][i]!=w){
			dfs2(tu[q][i],q);
		}
	}
	return;
}
inline void dfs3(int q,int w){
	if(w){
		ss[++tt]=q;
	}
	dep[q]=dep[w]+1;
	fa[q]=w;
	mxdep[q]=dep[q];
	cmax[q]=dep[q];
	for(int i=0;i<tu[q].size();i++){
		if(tu[q][i]!=w&&!vis[tu[q][i]]){
			dfs3(tu[q][i],q);
			if(mxdep[tu[q][i]]>mxdep[q]){
				cmax[q]=mxdep[q];
				mxdep[q]=mxdep[tu[q][i]];
			}
			else{
				cmax[q]=max(cmax[q],mxdep[tu[q][i]]);
			}
		}
	}
	maxx=max(maxx,dep[q]);
	return;
}
inline void dfs4(int q,int w){
	ss[++tt]=q;
	sz[q]=(mxdep[q]-dep[q]>=now);
	for(int i=0;i<tu[q].size();i++){
		if(!vis[tu[q][i]]&&tu[q][i]!=w){
			dfs4(tu[q][i],q);
			sz[q]+=sz[tu[q][i]];
		}
	}
	return;
}
inline int lca(int q,int w){
	while(q!=w){
		if(dep[q]<dep[w]){
			swap(q,w);
		}
		q=fa[q];
	}
	return q;
}
inline int get(int q,int w){
	now=w;
	int mx=0;
	for(int i=0;i<tu[q].size();i++){
		if(vis[tu[q][i]]){
			continue;
		}
		tt=0;
		dfs4(tu[q][i],0);
		for(int j=1;j<=tt;j++){
			fe[ss[j]]=ss[j];
			if(!sz[ss[j]]){
				continue;
			}
			for(int k=0;k<tu[ss[j]].size();k++){
				if(tu[ss[j]][k]==fa[ss[j]]){
					continue;
				}
				if(dep[fe[tu[ss[j]][k]]]<dep[fe[ss[j]]]){
					fe[ss[j]]=fe[tu[ss[j]][k]];
				}
			}
			while(dep[fa[fe[ss[j]]]]>=dep[tu[q][i]]&&mxdep[fa[fe[ss[j]]]]==mxdep[ss[j]]&&cmax[fa[fe[ss[j]]]]-2*dep[fa[fe[ss[j]]]]+dep[ss[j]]<=w){
				fe[ss[j]]=fa[fe[ss[j]]];
			}
			mx=max(mx,sz[fe[ss[j]]]-sz[ss[j]]);
		}
	}
	return mx;
}
inline int check(int q){
	pre=tp,suf=1;
	for(int i=1;i<=pre;i++){
		if(mxdep[st[i]]>=q){
			pre=i;
			break;
		}
		pre=min(pre,i+(q-mxdep[st[i]]));
	}
	for(int i=tp;i>=suf;i--){
		if(mxdep[st[i]]>=q){
			suf=i;
			break;
		}
		suf=max(suf,i-(q-mxdep[st[i]]));
	}
	ans=0;
	for(int i=1;i<=tp;i++){
		if(mxdep[st[i]]>=q){
			ans+=f[i][q];
		}
	}
	if(pre>suf){
		return 1;
	}
	ans+=suf-pre+1;
	val1[pre]=pre;
	for(int i=pre+1;i<=tp;i++){
		val1[i]=val1[i-1];
		while(val1[i]<i&&i-(q-mxdep[st[i]])>val1[i]){
			val1[i]++;
		}
	}
	val2[suf]=suf;
	for(int i=suf-1;i>=1;i--){
		val2[i]=val2[i+1];
		while(val2[i]>i&&i+(q-mxdep[st[i]])<val2[i]){
			val2[i]--;
		}
	}
	int mxx=0;
	for(int i=pre;i<suf;i++){
		mxx=max(mxx,val2[i+1]-val1[i]-1);
	}
	if(ans-mxx<=m){
		return 1;
	}
	for(int i=1;i<=tp;i++){
		if(mxdep[st[i]]>=q){
			if(ans-f[i][q]>m){
				continue;
			}
			if(ans-get(st[i],q)<=m){
				return 1;
			}
		}
	}
	return 0;
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	dep[0]=-1;
	cin>>sid>>T;
	while(T--){
		cin>>n>>m;
		for(int i=1;i<n;i++){
			cin>>x>>y;
			tu[x].push_back(y);
			tu[y].push_back(x);
		}
		rt=1;
		dfs1(1,0);
		fy=rt;
		dfs2(rt,0);
		tp=0;
		while(fy){
			st[++tp]=fy;
			vis[fy]=1;
			fy=fa[fy];
		}
		for(int i=1;i<=tp;i++){
			tt=0;
			dfs3(st[i],0);
			f[i].resize(maxx+1);
			for(int j=1;j<=tt;j++){
				f[i][mxdep[ss[j]]-dep[ss[j]]]++;
			}
			for(int j=maxx-1;j>=0;j--){
				f[i][j]+=f[i][j+1];
			}
		}
		int l=0,r=n;
		while(l<=r){
			int mid=(l+r)>>1;
			if(check(mid)){
				r=mid-1;
			}
			else{
				l=mid+1;
			}
		}
		cout<<l<<'\n';
		for(int i=1;i<=tp;i++){
			vector<int>().swap(f[i]);
		}
		for(int i=1;i<=n;i++){
			vis[i]=0;
			vector<int>().swap(tu[i]);
		}
	}
	return 0;
}
