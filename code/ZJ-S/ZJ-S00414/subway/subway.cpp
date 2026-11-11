#include<bits/stdc++.h>
using namespace std;
const int N=510,M=2e4+10,K=2e4+10;
int c,n,m,d,qry;
long long w[M],k[N],a[N][K],t[N][K];
long long dis[1010][1010],dis2[M];
queue<int> q;
struct node{
	int x;
	long long ti;
};
vector<node> e[M];
void solve1(){
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++) dis[i][j]=2e18;
	}
	for(int i=1;i<=m;i++){
		while(!q.empty()) q.pop();
		q.push(i);
		dis[i][i]=0;
		while(!q.empty()){
			int p=q.front();
			q.pop();
			for(node subway:e[p]){
				int sub=subway.x;
				long long tim=subway.ti;
				for(int j=1;j<=k[sub];j++){
					if(dis[i][a[sub][j]]>dis[i][p]+tim+t[sub][j]){
						q.push(a[sub][j]);
						dis[i][a[sub][j]]=dis[i][p]+tim+t[sub][j];
					}
				}
			}
		}
	}
	while(qry--){
		int x,y;
		cin>>x>>y;
		cout<<w[x]+w[y]+dis[x][y]<<'\n';
	}
}
void solve2(){
	while(qry--){
		for(int i=1;i<=m;i++) dis2[i]=2e18;
		int x,y;
		cin>>x>>y;
		while(!q.empty()) q.pop();
		q.push(x);
		dis2[x]=0;
		while(!q.empty()){
			int p=q.front();
			q.pop();
			for(node subway:e[p]){
				int sub=subway.x;
				long long tim=subway.ti;
				for(int j=1;j<=k[sub];j++){
					if(dis2[a[sub][j]]>dis2[p]+tim+t[sub][j]){
						q.push(a[sub][j]);
						dis2[a[sub][j]]=dis2[p]+tim+t[sub][j];
					}
				}
			}
		}
		cout<<w[x]+w[y]+dis2[y]<<'\n';
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>qry;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++) cin>>a[i][j]>>t[i][j];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k[i];j++){
			e[a[i][j]].push_back(node{i,t[i][j]});
		}
	}
	if(c<=11) solve1();
	else solve2();
	return 0;
}
