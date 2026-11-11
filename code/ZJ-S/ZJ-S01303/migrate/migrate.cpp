#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int nmax = 1159764;

using pll = pair<ll,ll>;
int n;
ll d,x[nmax];
// jiu zai gang gang
// 16:23
// yi zhi hen ke ai de fei e fei dao wo shou shang le ei
// mao rong rong de
// very cute awa
vector<ll>g[nmax];
int ways[nmax];
int dift[nmax];
bool vis[nmax];
// nan dao shuo T3 shi yi ge DAG shang de DP ?
// idk
void solve(){ // bao li solve() at least 24 pts
 cin>>n>>d;
 for(int i=1;i<=n;i++){
 	cin>>x[i];
 	g[i].clear();
	}
	for(int i=1;i+1<=n;i++){
		ll u=x[i];
		for(int j=i+1;j<=n;j++){
			ll v=x[j];
			if(v-u>d)break;
			g[i].push_back(j);
		}
	}
	ll ans=0;
	for(int i=1;i+1<=n;i++){
		for(int j=i;j<=n;j++)ways[j]=vis[j]=0,dift[j]=1e9;
		ways[i]=1;dift[i]=0;
		queue<int>q;
	 q.push(i);
		while(!q.empty()){
			int u=q.front();q.pop();
			if(vis[u]==1)continue;
			vis[u]=1;
			for(int v:g[u])
				if(dift[v]>dift[u]+1){
					q.push(v);
					dift[v]=dift[u]+1;
					ways[v]=ways[u];
				}else if(dift[v]==dift[u]+1){
					ways[v]+=ways[u];
					if(ways[v]>=20)ways[v]=20;
				}
		}
		int cnt=0;
		for(int j=i;j<=n;j++)
		 if(ways[j]==2)cnt++;
		ans+=cnt;
	}
	cout<<ans<<"\n";
	return;
};
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
 freopen("migrate.out","w",stdout);
int TEST_ID,CASE;cin>>TEST_ID>>CASE;
while(CASE--)solve();
	// fylfly is GOOD
	// ckr_taste_tasty is GOOD
 // www_ac is VERY GOOD
 // LvYiGe8888 is VERY GOOD
 // for me, rp++
 // luogu user 1159764
 
 // tai qiang la
 // Oct31==Dec25?
 // today is [ wan sheng ye ]
 return 0;
};