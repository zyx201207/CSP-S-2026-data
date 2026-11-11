#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
const int N=1000002;
int tp,T,n,m,u[102],v[102],fa[102],dis[102];
bool fl[102];
vector<int> tu[102];
queue<int> qe;
inline int find(int x){for(;fa[x]!=x;x=fa[x]=fa[fa[x]]);return x;}
inline void Merge(int x,int y){int fx=find(x),fy=find(y);if(fx^fy)fa[fx]=fy;}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",&tp,&T);
	for(;T--;){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;++i)
			tu[i].clear();
		for(int i=1;i<n;++i){
			scanf("%d%d",&u[i],&v[i]);
			tu[u[i]].emplace_back(v[i]),tu[v[i]].emplace_back(u[i]);
		}
		int mn=n;
		for(int t1=(1<<n)-1;t1>=0;--t1){
			for(int i=1;i<=n;++i)
				fl[i]=0,fa[i]=i;
			int cnt=0;
			for(int i=0;i<n;++i){
				if((t1>>i)&1)
					fl[i+1]=1,cnt++;
			}
			if(cnt!=m)
				continue;
			for(int i=1;i<n;++i){
				if(fl[u[i]]&&fl[v[i]])
					Merge(u[i],v[i]);
			}
			cnt=0;
			for(int i=1;i<=n;++i){
				if(fl[i]&&find(i)==i)
					cnt++;
			}
			if(cnt>2)
				continue;
			for(int i=1;i<=n;++i){
				if(fl[i]){
					dis[i]=0;
					qe.push(i);
				}
				else
					dis[i]=-1;
			}
			for(;!qe.empty();){
				int now=qe.front();
				qe.pop();
				for(int i=0;i<tu[now].size();++i){
					int v=tu[now][i];
					if(dis[v]==-1){
						dis[v]=dis[now]+1;
						qe.push(v);
					}
				}
			}
			cnt=0;
			for(int i=1;i<=n;++i)
				cnt=max(cnt,dis[i]);
			mn=min(mn,cnt);
		}
		printf("%d\n",mn);
	}
	return 0;
}
