#include<bits/stdc++.h>
#define int long long
#define p pair<int,int>
using namespace std;
int c,n,m,d,qq;
int dis[10005],a[5005],vis[5005];
vector<int> v[5005];
vector<int> w[5005];
priority_queue<p,vector<p>,greater<p> >q;
bool dij(int xx,int yy){
	memset(dis,0x3f3f3f3f,sizeof dis);
	memset(vis,0,sizeof vis);
	dis[xx]=0;
	q.push({0,xx});
	while(q.size()){
		p tmp=q.top();
		q.pop();
		int x=tmp.second;
		for(int i=0;i<v[x].size();i++){
			bool flag=0;
			int y=v[x][i],ww=w[x][i];
			if(dis[y]>=dis[x]+ww&&ww<=m){
				if(y==yy){
					vis[y]+=vis[x]+1;
				}else{
					vis[y]=vis[x]+1;	
				}
				dis[y]=dis[x]+ww;
				q.push({dis[y],y});
			}
		}
	}
	if(vis[yy]==8){
		return 1;
	}else{
		return 0;
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int Why,T;
	cin>>Why>>T;
	while(T--){
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			v[i].clear();
			w[i].clear();
		}
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				if(i==j) continue;
				v[i].push_back(j);
				w[i].push_back(abs(a[j]-a[i]));
			}
		}
		int cnt=0;
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				if(i==j) continue;
				if(dij(i,j)){
					cnt++;
				}	
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
} 
