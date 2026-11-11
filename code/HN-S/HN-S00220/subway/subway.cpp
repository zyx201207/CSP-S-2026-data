#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=503,M=5e5+9,Q=1e3+1;
struct ss{
	ll x,y;
};
bool operator < (const ss &s1,const ss &s2){
	return s1.y>s2.y;
}
ll n,m,d,qcq,c,w[M],dp[M],v[M],fg[Q][100009];
vector<ss>g[N],e[N];
map<int,int>mp;
priority_queue<ss>q;
void bfs(int x){
	memset(dp,0x3f,sizeof dp),dp[x]=0;
	memset(v,0,sizeof v);
	while(q.size())q.pop();
	q.push(ss{x,0});
	while(q.size()){
		ss k=q.top();
		q.pop();
		int u=k.x;
		if(v[u])continue;
		v[u]=1;
		for(auto i:e[u]){
			for(auto j:g[i.x]){
				if(j.x==u)continue;
				if(dp[j.x]>dp[u]+i.y+j.y){
					dp[j.x]=dp[u]+i.y+j.y;
					if(e[j.x].size()>1)q.push(ss{j.x,dp[j.x]});
				}
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>qcq;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1,z;i<=n;i++){
		cin>>z;
		for(int j=1,x,y;j<=z;j++){
			cin>>x>>y;
			g[i].push_back(ss{x,y});
			e[x].push_back(ss{i,y});
		}
	}
	for(int i=1;i<=qcq;i++){
		int l,r;
		cin>>l>>r;
		if(mp[l]==0){
			bfs(l),mp[l]=i;
			for(int j=1;j<=m;j++)fg[i][j]=dp[j];
		}
		else dp[r]=fg[mp[l]][r];
		cout<<dp[r]+w[l]+w[r]<<"\n";
	}
	return 0;
}
