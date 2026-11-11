#include<bits/stdc++.h>
#define ll long long
#define N 100005
using namespace std;
int c,n,m,D,q;
int w[N];
int k[505];
int tu[N][30];
ll dis[N];
int bh[N][505];
struct node{
	int x,id;
	ll d;
};
map<pair<int,int>,ll>mp;
vector<node>e[N];
queue<node>pq;
int vis[N];
int t[N];
int tl;
void dij(int s){
	for(int i=1;i<=m;++i)dis[i]=1e18;
	dis[s]=0;
	for(int i=1;i<=tu[s][0];++i){
			int nw=tu[s][i];
			for(int j=0;j<e[nw].size();++j){
				int t=e[nw][j].x;
//				cout<<"here";
				if(t==s)continue;
				dis[t]=e[nw][bh[s][nw]].d+e[nw][j].d;
				pq.push((node){t,nw,dis[t]});
				mp[make_pair(s,t)]=mp[make_pair(t,s)]=dis[t];
			}
		}
	while(!pq.empty()){
//		cout<<"c";
		int x=pq.front().x,id=pq.front().id;
		pq.pop();
		for(int i=1;i<=tu[x][0];++i){
//			cout<<"d"<<endl;
			int nw=tu[x][i];
//			cout<<nw<<' '<<id<<endl;
			if(nw==id)continue;
			ll w1=e[nw][bh[x][nw]].d;
//			cout<<e[nw].size()<<' ';
			for(int j=0;j<e[nw].size();++j){
//				cout<<"e"<<endl;
				int t=e[nw][j].x;
				int w=w1+e[nw][j].d;
				if(dis[t]>dis[x]+w){
					dis[t]=dis[x]+w;
//					cout<<"zhuyi"<<x<<' '<<t<<' '<<dis[t]<<endl;
//					cout<<dis[x]<<' '<<dis[t]<<' '<<t<<endl;
					pq.push((node){t,nw,dis[t]});
					mp[make_pair(s,t)]=mp[make_pair(t,s)]=dis[t];
				}
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout); 
	scanf("%d%d%d%d%d",&c,&n,&m,&D,&q);
	for(int i=1;i<=m;++i){
		scanf("%d",&w[i]); 
	}
	for(int i=1;i<=n;++i){
		scanf("%d",&k[i]);
		for(int j=1;j<=k[i];++j){
			int x;
			ll d;
			scanf("%d%lld",&x,&d);
			node tmp;
			tmp.d=d,tmp.x=x;
			e[i].push_back(tmp);
			bh[x][i]=j-1;
			tu[x][++tu[x][0]]=i;
		}
	}
//	cout<<"b"<<endl;
	for(int i=1;i<=q;++i){
		int x,y;
		scanf("%d%d",&x,&y);
		if(!mp[make_pair(x,y)])
			dij(x);
		else dis[y]=mp[make_pair(x,y)];
//		cout<<"a"<<endl;
		printf("%lld\n",w[x]+w[y]+dis[y]);
	}
	return 0;
} 
