#include<bits/stdc++.h>
#define int long long
using namespace std;
const int M=5e5+7;
const int N=501;
const int INF=1e18+7;
struct node{
	int sum;
	int num[21];
	int val[21];
};
int c,n,m,d,q;
int w[M];
int k[N];
vector<pair<int,int> > edge[N];//从n号线换到别的线的价值(不会重边) 
node sub[M];//经过第i个站点的地铁 

void init(){
	for(int i=1;i<=m;i++){
		if(sub[i].sum>1){
			for(int j=1;j<=sub[i].sum-1;j++){
				for(int k=j+1;k<=sub[i].sum;k++){
					int startp=sub[i].num[j];
					int endp=sub[i].num[k];
					int value=sub[i].val[j]+sub[i].val[k];
					edge[startp].push_back({endp,value});
					edge[endp].push_back({startp,value});
				}
			}
		}
	}
}
int dis[N][N];//从i出发到j的最短路 
bool operator <(pair<int,int> a,pair<int,int> b){
	return a.second<b.second;
}
void dijia(int x){//从x出发 
	priority_queue<pair<int,int> > Q;//可能可以更新别人最短路的点,现在的最短路值 
	for(int i=1;i<=n;i++){
		dis[x][i]=INF;
	}
	dis[x][x]=0;
	Q.push({x,0});
	while(Q.size()){
		auto now=Q.top();
		Q.pop();
		for(auto next:edge[now.first]){
			int pos=next.first;
			int value=next.second;
			if(dis[x][pos]>now.second+value){
				dis[x][pos]=now.second+value;
				Q.push({pos,dis[x][pos]});
			}
		}
	}
} 
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int zhan,timer;
			cin>>zhan>>timer;
			int nowsum=sub[zhan].sum;
			nowsum++;
			sub[zhan].sum++;
			sub[zhan].num[nowsum]=i;
			sub[zhan].val[nowsum]=timer;
		}
	}
	init();
	for(int i=1;i<=n;i++){
		dijia(i);
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		int ans=INF;
		for(int i=1;i<=sub[x].sum;i++){
			for(int j=1;j<=sub[y].sum;j++){
				int startsub=sub[x].num[i];
				int endsub=sub[y].num[j];
				ans=min(ans,dis[startsub][endsub]+w[x]+w[y]+sub[x].val[i]+sub[y].val[j]);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
