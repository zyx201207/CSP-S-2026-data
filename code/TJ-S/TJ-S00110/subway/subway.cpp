#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=1e5+10,N=5e2+10;
int c,n,m,d,q;
int w[M],k[N],a[N][M],t[N][M];
vector<int> xianlu[M];
int dis[M];
bool xlused[N];
int bfs(int start,int end){
	queue<pair<int,int> > q;
	for(int xl:xianlu[start]){
		xlused[xl]=1;
		for(int x=1;x<=k[xl];x++){
			q.push({a[xl][x],0});
			dis[a[xl][x]]=0;
		}
	}
	while(!q.empty()){
		auto xxx=q.front();
		q.pop();
		int now=xxx.first,step=xxx.second;
		if(now==end){
			return step;
		}
		for(int xl:xianlu[now]){
			if(xlused[xl]){
				continue;
			}
			for(int x=1;x<=k[xl];x++){
				if(dis[a[xl][x]]==0x3f3f3f3f){
					q.push({a[xl][x],step+1});
					dis[a[xl][x]]=step+1;
				}
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>c>>n>>m>>d>>q;
	
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	int T;
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			T=t[i][j];
			xianlu[a[i][j]].push_back(i);
		}
	}
	while(q--){
		memset(dis,0x3f,sizeof(dis));
		memset(xlused,0,sizeof(xlused));
		int x,y;
		cin>>x>>y;
		int ans=bfs(x,y);
		cout<<(ll)w[x]+w[y]+(ll)ans*2*T<<'\n';
	}
	
	return 0;
}
