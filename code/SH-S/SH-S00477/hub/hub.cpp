#include<bits/stdc++.h>
using namespace std;
const int N=5e6+10,M=5010;
int len[1010];
bool book[N];
int b[N],cp[1010][1010];
int n,k;
typedef pair<int,int> PII;
vector<int> g[N];
int ans=INT_MAX;
void  dijkstra(){
	priority_queue<PII> q;
	for(int i=1;i<=k;i++){
		book[b[i]]=0;
	}
	for(int i=1;i<=k;i++){
		q.push({0,b[i]});
		book[b[i]]=1;
	}
	memset(len,0x3f,sizeof(len));
	len[0]=0;
	while(!q.empty()){
		int u=q.top().second,v=q.top().first;
		q.pop();
		len[u]=min(len[u],v);
		for(auto o:g[u]){
			if(len[o]==0&&book[o]!=1||len[o]>v+1){
				q.push({v+1,o});
			}
		}
	}
}
bool check1(int x,int y){
	if(x!=len[n]||y!=len[n])return false;
	for(int i=1;i<=len[x];i++){
		for(auto u:g[x]){
			if(len[u]==len[x]-1){
				x=u;
				break;
			}
		}
		for(auto u:g[y]){
			if(len[u]==len[y]-1){
				y=u;
				break;
			}
		}
	}
	return x!=y;
}
bool check(int x){
	int i=n,cnt=0;
	for(int j=1;j<=n;j++){
		for(int k=j;k<=n;k++){
			if(cp[j][k]>=1&&check1(j,k)){
				cnt++;
			}
		}
	}
	return cnt<=2;
}
void dfs(int x,int y){
	if(x==n+1){
		if(y==k+1){
			dijkstra();
			sort(len+1,len+n+1);
			if(check(len[n]))ans=min(ans,len[n]);
		}
		return;
	}
	b[y]=x;
	dfs(x+1,y+1);
	b[y]=0;
	dfs(x+1,y);
}

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			cp[u][v]=1;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		ans=INT_MAX;
		dfs(1,1);
		cout<<ans<<"\n";
	}
	return 0;
} 

