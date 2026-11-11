#include<iostream>
#include<vector>
#include<queue>
using namespace std;
//T2
//subway
//pts=[44,60] 
#define int long long
struct edge{
	int to,val;
};
bool operator < (const edge x,const edge y){
	return x.val>y.val;
}
bool operator > (const edge x,const edge y){
	return y<x;
}
const int MAXN=1e17+7;
int m,w[500],c,n,d,q;
int dis[500505];
bool vis[500505];
vector<edge> a[500505];
priority_queue<edge> qu;
int dij(int x,int y){
	for(int i=1;i<=m+500;i++){
		vis[i]=false;
		dis[i]=MAXN;
	}
	qu.push({x,0});
	vis[x]=true;
	dis[x]=0;
	for(;!qu.empty();){
		edge tmp=qu.top();
		int now=tmp.to;
//		cout<<now<<endl;
		qu.pop();
		for(int i=0;i<a[now].size();i++){
//			cout<<(vis[a[now][i].to]?"yes":"nonono")<<endl;
//			cout<<now<<' '<<a[now][i].to<<' '<<dis[a[now][i].to]<<endl;
			if(!vis[a[now][i].to]){
//				cout<<now<<' '<<a[now][i].to<<' '<<dis[a[now][i].to]<<endl;
				vis[a[now][i].to]=true;
				dis[a[now][i].to]=min(dis[a[now][i].to],tmp.val+a[now][i].val);
				qu.push({a[now][i].to,tmp.val+a[now][i].val});
			}
//			cout<<now<<' '<<a[now][i].to<<' '<<dis[a[now][i].to]<<endl;
		}
	}
	return dis[y];
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
//	freopen("subway4.in","r",stdin);
//	freopen("test.ans","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int x,i=1;i<=n;i++){
		cin>>x;
		for(int j=1,y,z;j<=x;j++){
			cin>>y>>z;
			a[y].push_back({m+i,z});
			a[m+i].push_back({y,z});
		}
	}
	for(int x,y;q--;){
		cin>>x>>y;
//		cout<<"-------------\n";
		cout<<(w[x]+w[y]+dij(x,y))<<endl;
	}
	return 0;
} 
/*
Oct31==Dec25?
*/
