#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read(){
	int ret=0;bool opt=0;char in=getchar();
	while(!isdigit(in)){opt|=(in=='-');in=getchar();}
	while(isdigit(in)){ret=ret*10+(in^48);in=getchar();}
	return (opt?-ret:ret);
}
struct lin{int suc,len;};
typedef vector<lin> vec;
int dotc,wayc,knum,proc;
int dis[510][510];
int valt[500010];
vec lins[500510];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int test=read();
	wayc=read();dotc=read();
	knum=read();proc=read();
	for(int i=1;i<=dotc;i+=1){
		valt[i]=read();
	}for(int i=1;i<=wayc;i+=1){
		int x=read(),u=i+dotc;
		for(int j=1;j<=x;j+=1){
			int v=read(),w=read();
			lins[u].push_back({v,w});
			lins[v].push_back({u,w});
		}
	}for(int i=1;i<=wayc;i+=1){
		for(int j=1;j<=wayc;j+=1){
			dis[i][j]=1e18;
		}dis[i][i]=0;
	}for(int i=1;i<=dotc;i+=1){
		for(auto [x,m]:lins[i]){
			for(auto [y,n]:lins[i]){
				int p=x-dotc,q=y-dotc;
				if(p==q)continue;
				dis[p][q]=min(dis[p][q],m+n);
			}
		}
	}for(int k=1;k<=wayc;k+=1){
		for(int i=1;i<=wayc;i+=1){
			for(int j=1;j<=wayc;j+=1){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}for(int i=1;i<=proc;i+=1){
		int u=read(),v=read(),ret=1e18;
		for(auto [x,m]:lins[u]){
			for(auto [y,n]:lins[v]){
				int p=x-dotc,q=y-dotc;
				ret=min(ret,dis[p][q]+m+n);
			}
		}ret+=valt[u]+valt[v];
		printf("%lld\n",ret);
	}return 0;
}