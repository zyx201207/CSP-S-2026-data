// __       ___________________________________
// \ \     / /____  ____|  _______ \_____  ____|
//  \ \   / /    | |    | |______| |    | |
//   \ \ / /     | |    |         /     | |
//   /  ^ \      | |    |  ______ \     | |
//  / /  \ \     | |    | |______| |    | |
// /_/    \_\    |_|    |_________|     |_|
#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define lowbit(x) (x & -x)
#define INF 0x3f3f3f3f3f3f3f3fll
#define inf 0x3f3f3f3f
#define FINF 0xcfcfcfcfcfcfcfcfll
#define finf 0xcfcfcfcf
using namespace std;
const int maxn=4e3+5;
const int maxm=1e6;
const int mod=998244353;
int n,m,t,k,ooo,Q;
int a[maxn];
int b[maxn][maxn];
int c[maxn];
vector<pair<int,int>>vc[maxn];
queue<int>q;
void SPFA(int o){
	q.push(o);
	b[o][o]=0;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		c[u]=0;
		for(int i=0;i<(int)vc[u].size();i++){
			pair<int,int>p=vc[u][i];
			int v=p.first,w=p.second;
			if(b[o][v]>b[o][u]+w){
				b[o][v]=b[o][u]+w;
				if(!c[v]){
					q.push(v);c[v]=1;
				}
			}
		}
	}
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	//°§±ø±ØÊ¤
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
//	freopen("subway4.in","r",stdin);
//	freopen("jmcakioi.txt","w",stdout);
	cin>>ooo>>n>>m>>k>>Q;
if(ooo==9||ooo==10||ooo==11){
	for(int i=1;i<=m;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		int u;
		cin>>u;
		for(int j=1;j<=u;j++){
			int v,w;
			cin>>v>>w;
			vc[i+m].push_back({v,w});
			vc[v].push_back({i+m,w});
		}
	}
	memset(b,0x3f,sizeof(b));
	for(int i=1;i<=m;i++){
		SPFA(i);
	}
while(Q--){
	int u,v;
	cin>>u>>v;
	cout<<a[u]+a[v]+b[u][v]<<endl;
}
	return 0;
}
	memset(b,0x3f,sizeof(b));
	for(int i=1;i<=n+m;i++)b[i][i]=0;
	for(int i=1;i<=m;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		int u;
		cin>>u;
		for(int j=1;j<=u;j++){
			int v,w;
			cin>>v>>w;
			b[i][v+n]=w;
			b[v+n][i]=w;
		}
	}
	for(int i=1;i<=n+m;i++){
		for(int j=1;j<=n+m;j++){
			for(int k=1;k<=n+m;k++){
				b[j][k]=min(b[j][i]+b[i][k],b[j][k]);
			}
		}
	}
while(Q--){
	int u,v;
	cin>>u>>v;
	cout<<b[u+n][v+n]+a[u]+a[v]<<endl;
}
	
	return 0;
}

