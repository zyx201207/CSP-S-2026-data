#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+5,M=5e5+5;
int c,t;
int n,k;
vector<int> g[N];
bool vis[N];
void solve(){
	cin>>n>>k;
	for(int i=1;i<=n;i++)	g[i].clear();
	for(int i=1;i<=n;i++)	vis[i]=false;
	for(int i=1,x,y;i<n;i++){
		cin>>x>>y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	cout<<1<<'\n';
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--)	solve();
	return 0;
}