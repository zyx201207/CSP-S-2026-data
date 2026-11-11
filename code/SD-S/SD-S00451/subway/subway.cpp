#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<climits>
#include<string>
#include<algorithm>
#include<stack>
#include<queue>
#include<list>
#include<vector>
#include<map>
#include<set>
#include<utility>
using namespace std;
#define ll long long
#define pii pair<ll,ll>
const int N=5e5+5;
int C,n,m,d,p,b[N],k[N],a[N][30],t[N][30];
//ll dis[N];
vector<pii > g[N];
vector<int> dis,cl;
bool vis[N];
priority_queue<pii,vector<pii >,greater<pii > > q;
void djstl(int s){
	q.push({0,s});
	dis[s]=0;
	while(!q.empty()){
		pii f=q.top();q.pop();
		int u=f.second;
		vis[u]=0;
		for(pii i:g[u]){
			ll v=i.first,d=i.second;
			if(dis[v]>d+f.first){
				dis[v]=d+f.first;
				if(!vis[v]) q.push({dis[v],v}),vis[v]=1; 
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>C>>n>>m>>d>>p;
	for(int i=1;i<=m;i++) cin>>b[i],dis.push_back(0x3f3f3f3f);
	cl=dis;
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++) cin>>a[i][j]>>t[i][j];
		for(int j=1;j<=k[i];j++)
			for(int l=1;l<=k[i];l++)
				if(j!=l) g[a[i][j]].push_back({a[i][l],t[i][j]+t[i][l]});
	}
	for(int i=1;i<=p;i++){
		int x,y;
		cin>>x>>y;
		dis=cl;
		djstl(x);
		cout<<b[x]+b[y]+dis[y]<<"\n";
	}
	return 0;  
}
