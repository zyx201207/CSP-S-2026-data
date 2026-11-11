#include<bits/stdc++.h>
#define int long long
using namespace std;
#define inf 1000000007
struct edge{
	int to,val;
};
vector<edge> G[255000],Kanterjavik;
int n,m,c,d,q,w[5050],dis[5050][5050],di[255000];
bool operator < (const edge &u,const edge &v){
	return u.val<v.val;
}
priority_queue<edge> Q;
main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		int v[550]={0};
		int t[550]={0};
		for(int j=1;j<=k;j++){
			cin>>v[j]>>t[j];
		}
		for(int j=1;j<=k;j++){
			for(int o=1;o<=k;o++){
				if(j==o) continue;
				G[v[o]].push_back({v[j],t[j]+t[o]});
			}
		}
	}
	if(c<=8||c==20||c==21)// 空间足够且dis不会越界时空间换时间 DJT
	{
		for(int p=1;p<=m;p++){
			for(int i=1;i<=m;i++){
				dis[p][i]=inf;
			}
			dis[p][p]=0;
			Q.push({p,dis[p][p]});
			while(!Q.empty()){
				int u=Q.top().to;
				int val=Q.top().val;
				Q.pop();
				for(int i=0;i<G[u].size();i++){
					int w=G[u][i].val;
					int v=G[u][i].to;
					if(dis[p][v]>dis[p][u]+w){
						dis[p][v]=dis[p][u]+w;
						Q.push({v,dis[p][v]});
					}
				}
			}
			for(int i=1;i<=m;i++){
				dis[p][i]+=w[p]+w[i];
			}
		}
		for(int i=1;i<=q;i++){
			int l,r;
			cin>>l>>r;
			cout<<dis[l][r]<<"\n";
		}
	}else{//否则时间换空间看运气 qwq
		for(int i=1;i<=q;i++){
			int p,r;
			cin>>p>>r;
			for(int i=1;i<=m;i++){
				di[i]=inf;
			}
			di[p]=0;
			Q.push({p,di[p]});
			while(!Q.empty()){
				int u=Q.top().to;
				int val=Q.top().val;
				Q.pop();
				for(int i=0;i<G[u].size();i++){
					int w=G[u][i].val;
					int v=G[u][i].to;
					if(di[v]>di[u]+w){
						di[v]=di[u]+w;
						Q.push({v,di[v]});
					}
				}
			}
			for(int i=1;i<=m;i++){
				di[i]+=w[p]+w[i];
			}
			cout<<di[r]<<"\n";
		}
	}
	return 0;
}/*
===================================
    C S P - S  T 2  subway.cpp
    - about 40 PTS
=================================== 
*/

