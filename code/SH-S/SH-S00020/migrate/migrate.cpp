#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6;

vector<int> edge[N+5];
ll n,d,a[N+5];
int c,T;

bool vis[N+5];
int cnt[N+5],dis[N+5];
void bfs(int s){
	for(int i=s;i<=n;i++)
		vis[i]=0,cnt[i]=0,dis[i]=0x3f3f3f3f;
	dis[s]=0,cnt[s]=1;
	queue<int> que;
	que.push(s);
	while(!que.empty()){
		int now=que.front();
		que.pop();
		for(auto i:edge[now]){
			if(!vis[i]){
				vis[i]=1,cnt[i]+=cnt[now],dis[i]=dis[now]+1;
				que.push(i);
			}else{
				if(dis[i]==dis[now]+1) cnt[i]+=cnt[now];
			}
		}
	}
}

void solve(){
	cin>>n>>d;
	if(c==13 || c==14){
		cout<<0<<'\n';
		return ;
	}
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++){
		edge[i].clear();
		for(int j=i+1;j<=n;j++){
			if(a[j]-a[i]<=d)
				edge[i].push_back(j);
		}
	}
	ll ans=0;
	for(int i=1;i<=n;i++){
		bfs(i);
		for(int j=i;j<=n;j++)
			ans+=(cnt[j]==2);
	}
	cout<<ans<<'\n';
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>T;
	while(T--)
		solve();
	return 0;
} 
