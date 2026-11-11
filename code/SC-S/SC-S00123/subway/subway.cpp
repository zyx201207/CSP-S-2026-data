#include<bits/stdc++.h>
using namespace std;
const int INF=0x3f;
 struct edge{
	 int xl,t;
 };
vector<vector<long long>>xd(200005);
vector<vector<edge>>ti(200005);
long long vis[200005];
void fi(int u,int v,int i,long long t){
	for(int j=0;j<(int)ti[i].size();j++){
		t=ti[u][i].t;
		vis[u]=t;
		for(auto j:xd[i]){
			if(vis[j]==0){
				for(int k=0;k<(int)ti[i].size();k++){
					t+=ti[j][i].t;
					fi(j,v,ti[j][k].xl,t);
					t-=ti[j][i].t;
				}
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("subway1.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	vector<long long>jbsj(n);
	for(int i=0;i<m;i++){
		cin>>jbsj[i];
	}
	for(int i=0;i<n;i++){
		int k;
		cin>>k;
		for(int i=0;i<k;i++){
			int z,t;
			cin>>z>>t;
			ti[z].push_back({i,t});
			xd[i].push_back(z);
		}
	}
	for(int i=0;i<q;i++){
		int u,v;
		cin>>u>>v;
		memset(vis,INF,sizeof(vis));
		vis[u]=0;
		fi(u,v,i,0);
		cout<<vis[v]+jbsj[u]+jbsj[v]<<endl;
	}
	return 0;
}