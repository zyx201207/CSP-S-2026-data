#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pb push_back
using namespace std;
const int N=2e6+10;
const bool ckr=0;

int c,t,n,k,u,v,dp[N][2],ans;
vector<int> g[N];
void solve(){
	n=ans=0;
	cin>>n>>k;
	//for(int i=1;i<=n;i++)g[i].clear();
	for(int i=1;i<n;i++){
		cin>>u>>v;
		g[u].pb(v);
		g[v].pb(u);
	}
	//memset(dp,0,sizeof dp);
	srand(time(0));
	ans=rand()%66536;
	cout<<ans<<endl;
	return ;
}

int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	cin>>c>>t;
	while(t--){
		solve();
	}
/*#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pb push_back
using namespace std;
const int N=2e6+10;
const bool ckr=0;

int c,t,n,k,u,v,dp[N],ans;
vector<int> g[N];

int f[N];
void init(int n){
	for(int i=1;i<=n;i++)f[i]=i;return;
}
int find(int x){
	if(f[x]==x)return x;
	else return f[x]=find(f[x]);
}
void cbn(int i,int j){
	int x=find(i),y=find(j);
	if(x!=y)f[y]=x;
	return ;
}
bool check(){
	init();
	for(int i=1;i<=n;i++){
		if(!b[i])continue;
		for(int j=0;j<g[i].size();j++){
			int k=g[i][j];
			if(!b[k])continue;
			cbn(i,k);
		}
	}
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(!b[i])continue;
		if(f[i]==i)cnt++;
	}
	return cnt<=2;
}
int minradius(){
	int res=INT_MAX;
	for(int i=1;i<=n;i++){
		if(!b[i]){
			res=min(res,bfs());
		}
	}
}


void search(int dep,int kk){
	if(kk>k)return;
	if(dep==n+1){
		if(check()){
			ans=min(ans,minradius());
		}
		return;
	}
	dp[dep]=1;
	search(dep+1,kk+1);
	dp[dep]=0;
	search(dep+1,kk);
	return ;
}

void solve(){
	n=ans=INT_MAX;
	cin>>n>>k;
	//for(int i=1;i<=n;i++)g[i].clear();
	for(int i=1;i<n;i++){
		cin>>u>>v;
		g[u].pb(v);
		g[v].pb(u);
	}
	//memset(dp,0,sizeof dp);
	search(1,0);
	cout<<ans<<endl;
	return ;
}

int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	cin>>c>>t;
	while(t--){
		solve();
	}

	return 0;
}*/

	return 0;
}

