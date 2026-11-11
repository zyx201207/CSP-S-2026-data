#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q,v[500005],k,a1,a2,dis[1000005],cnt,g[1000005];
queue<int> que;
struct node{
	int to,w;
};
vector<node> s[1000005];
void spfa(int x){
	memset(dis,0x3f3f3f3f3f3f3f,sizeof(dis));
	memset(g,0,sizeof(g));
	que.push(x);
	dis[x]=0,g[x]=1;
	while(!que.empty()){
		int u=que.front();	
		que.pop();
		g[u]=0;
		for(int i=0;i<s[u].size();i++){
			if(dis[s[u][i].to]>dis[u]+s[u][i].w){
				dis[s[u][i].to]=dis[u]+s[u][i].w;
				if(!g[i])que.push(s[u][i].to);
			}
		}
	}
}
signed main(){
ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>v[i];
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a1>>a2;
			s[m+i].push_back({a1,a2});
			s[a1].push_back({m+i,a2});
		}
	}
	for(int i=1;i<=q;i++){
		cin>>a1>>a2;
		spfa(a1);
		cout<<dis[a2]+v[a1]+v[a2]<<endl;
	}
	return 0;
}
