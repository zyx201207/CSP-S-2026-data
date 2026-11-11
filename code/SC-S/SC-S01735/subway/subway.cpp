#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define int long long
vector<int>v[505];
const int N=505;
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >q;
int dis[N][N],a[N],b[N],val[N][N],in[N];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int cc,n,m,d,qq;cin>>cc>>n>>m>>d>>qq;
	memset(val,0x3f,sizeof(val));
	for(int i=1;i<=m;i++)cin>>in[i];
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int j=1;j<=k;j++)
			cin>>a[j]>>b[j];
		for(int x=1;x<=k;x++){
			for(int y=1;y<=k;y++){
				if(x==y)continue;
				v[a[x]].push_back(a[y]);
				v[a[y]].push_back(a[x]);
				val[a[x]][a[y]]=min(val[a[x]][a[y]],b[x]+b[y]);
				val[a[y]][a[x]]=min(val[a[y]][a[x]],b[y]+b[x]);
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<"P";
		for(int j=0;j<v[i].size();j++)
			cout<<v[i][j]<<' ';
		cout<<endl;
	}
	for(int k=1;k<=m;k++){
		memset(dis[k],0x3f,sizeof(dis[k]));
		dis[k][k]=0; q.push(mp(0,k));
		while(!q.empty()){
			int t=q.top().second;q.pop();
			for(int i=0;i<v[t].size();i++){
				int w=v[t][i];
				if((dis[k][w]>dis[k][t]+val[t][w])){
					dis[k][w]=dis[k][t]+val[t][w];
					q.push(mp(dis[k][w],w));
				}
			}
		}
	}
	for(int i=1;i<=qq;i++){
		int x,y;cin>>x>>y;
		cout<<dis[x][y]+in[x]+in[y]<<'\n';
	}
	return 0;
} 