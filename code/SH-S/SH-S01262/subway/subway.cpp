#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN=5e5+5;
int c,n,m,d,qq,w[MAXN],dis[MAXN],x[505][MAXN];
struct node{
	int i,dis,tr;
};
struct N{
	int tr,t;
};
vector <N> v[MAXN];
vector <int> tri[505];
bool flag[MAXN];
queue<node> q;

void SPFA(int s){
	flag[s]=true;
	dis[s]=0;
	for(auto trial:v[s])
		q.push({s,trial.t,trial.tr});
	while(!q.empty()){
		int u=q.front().i,d=q.front().dis,tr=q.front().tr;
		q.pop();
		flag[u]=false;
		for(auto tg:tri[tr])
			if(dis[tg]>d+x[tr][tg]){
				dis[tg]=d+x[tr][tg];
				if(!flag[tg])
					for(auto trial:v[tg]){
						q.push({tg,dis[tg]+trial.t,trial.tr});
						flag[tg]=true;
					}
			}
	}
}

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>qq;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			v[a].push_back({i,t});
			tri[i].push_back(a);
			x[i][a]=t;
		}
	}
	for(int i=1;i<=qq;i++){
		memset(dis,0x7f,sizeof(dis));
		memset(flag,false,sizeof(false));
		int s,t;
		cin>>s>>t;
		SPFA(s);
		cout<<dis[t]+w[t]+w[s]<<endl;
	}
	return 0;
}
