#include<bits/stdc++.h>
#define int long long
using namespace std;
void IOS(){ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
int c,t;
const int N=2e6+5;
const int INF=1e18;
int n,d,a[N];
vector<int> g[N];
int dis[N],dis2[N];
bool vis[N];
queue<int> q;
void bfs(int st){
	for(int i=1;i<=n;++i)dis[i]=INF,dis2[i]=0,vis[i]=0;
	q.push(st);
	dis[st]=0,dis2[st]=1,vis[st]=1;
	while(!q.empty()){
		int p=q.front();
		q.pop();
		for(int v:g[p]){
			if(dis[v]>dis[p]+1){
				dis[v]=dis[p]+1;
				dis2[v]=dis2[p];
			}
			else if(dis[v]==dis[p]+1)dis2[v]+=dis2[p];
			if(vis[v])continue;
			vis[v]=1;
			q.push(v);
		}
	}
}
void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		g[i].clear();
	}
	if(n<=3){
		cout<<"0\n";
		return ;
	}
	bool k=0;
	int kl=a[2]-a[1];
	for(int i=3;i<=n;++i){
		if(a[i]-a[i-1]!=kl){
			k=1;
			break;
		}
	}
	if(!k){
		d/=kl;
		if(d<=1){
			cout<<"0\n";
			return ;
		}
		d*=2;
		cout<<max(0ll,n-d+1)<<"\n";
		return ;
	}
	for(int i=1;i<=n;++i){
		int j=i+1;
		while(j<=n&&a[j]-a[i]<=d){
			g[i].push_back(j);
			j++;
		}
	}
	int ans=0;
	for(int i=1;i<=n;++i){
		bfs(i);
		for(int j=i+1;j<=n;++j)ans+=(dis2[j]==2);
	}
	cout<<ans<<"\n";
}
signed main(){
	IOS();
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)solve();
	return 0;
}
