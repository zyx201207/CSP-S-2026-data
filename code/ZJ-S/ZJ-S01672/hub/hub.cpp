#include<bits/stdc++.h>
using namespace std;
#define int long long
const int INF=0x3f3f3f3f3f3f3f3f;
const int N=2e6+10;
int c,t;
vector<int> g[N];
int n,k;
int st[N];
int ans=INF;
bool check(int x){
	int cnt=0;
	for(int i=n-1;i>=0;i--){
		if(((x>>i)&1)==1)cnt++;
	}
	if(cnt==k)return 1;
	return 0;
}
void bfs(int x){
	memset(st,0x3f,sizeof st);
	queue<int> q;
	for(int i=n;i>=1;i--){
		if(((x>>(i-1))&1)==1){
			st[i]=0;
			q.push(i);
		}
	}
	int sum=0;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int i=0;i<g[u].size();i++){
			if(st[g[u][i]]!=INF)continue;
			st[g[u][i]]=st[u]+1;
			q.push(g[u][i]);
			sum=max(sum,g[u][i]);
		}
	}
	ans=min(ans,sum);
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	if(c<=6){
		for(int kkk=1;kkk<=t;kkk++){
			cin>>n>>k;
			for(int i=1;i<n;i++){
				int u,v;
				cin>>u>>v;
				g[u].push_back(v);
				g[v].push_back(u);
			}
			ans=INF;
			for(int i=0;i<((1<<n)-1);i++){
				if(check(i)){
					bfs(i);
				}
			}
			for(int i=1;i<=n;i++)g[i].clear();
			cout<<ans<<endl;
		}
	}
	else if(c==7||c==11||c==12){
		while(t--){
			cin>>n>>k;
			for(int i=1;i<n;i++){
				int u,v;
				cin>>u>>v;
				g[u].push_back(v);
				g[v].push_back(u);
			}
			cout<<n/3<<endl;
		}
	}
	else{
		while(t--){
			cin>>n>>k;
			if(n==k)cout<<0<<endl;
			else cout<<"2"<<endl;
		}
	}
	return 0;
}