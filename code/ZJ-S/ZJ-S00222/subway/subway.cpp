#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,x,y,go[505][505],w[500005],k[505];
struct node{
	long long w;
	int v;
};
vector<node>zhan[500005];
vector<node>dui[505];
bool cmp(node x,node y){
	return x.v<y.v;
}
inline int read(){
	int k=0,f=1;
	char c;
	c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-'){
			f=-f;
		}
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		k=k<<3+k<<1+c-'0';
		c=getchar();
	}
	return k*f;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(register int i=1;i<=m;++i){
		w[i]=read();
	}
	for(int i=1;i<=n;++i){
		k[i]=read();
		dui[i].resize(k[i]);
		for(int j=1;j<=k[i];++j){
			x=read();y=read();
			node xxx;xxx.v=x;xxx.w=y;
			dui[i][j-1]=xxx;
			xxx.v=i;
			zhan[x].push_back(xxx);
		}
		sort(dui[i].begin(),dui[i].end(),cmp);
	}
	for(int i=1;i<=n;++i){
		for(int j=i+1;j<=n;++j){
			go[i][j]=1000000000000000LL;
			int l=0,r=0,szi=dui[i].size(),szj=dui[j].size();
			while(l<szi&&r<szj){
				if(dui[i][l].v==dui[j][r].v){
					go[i][j]=min(go[i][j],dui[i][l].w+dui[j][r].w);
					++l;++r;
				}else{
					if(dui[i][l].v<dui[j][r].v){
						++l;
					}else{
						++r;
					}
				}
			}
		}
	}
	for(register int k=1;k<=n;++k){
		for(register int i=1;i<n;++i){
			for(register int j=i+1;j<=n;++j){
				go[i][j]=min(go[i][j],go[min(i,k)][max(i,k)]+go[min(j,k)][max(j,k)]);
			}
		}
	}
	while(q--){
		x=read();y=read();
		long long ans=1001000000000000LL;
		for(int i=0;i<zhan[x].size();++i){
			long long u=zhan[x][i].v,uu=zhan[x][i].w;
			for(int j=0;j<zhan[y].size();++j){
				long long v=zhan[y][j].v,vv=zhan[y][j].w;
				int mi=min(u,v),ma=max(u,v);
				if(go[mi][ma]+vv+uu<ans){
					ans=go[mi][ma]+vv+uu;
				}
			}
		}
		cout<<ans+w[x]+w[y]<<'\n';
	}
}