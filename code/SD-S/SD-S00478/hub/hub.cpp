#include<bits/stdc++.h>
#define int long long
#define mod 998244353
#define mp make_pair
using namespace std;

int c,t,n,k;
vector<int> g[2000005];

void solve1(){
	if(k==n){cout<<0;return;}
	int m=(n-1)/2,ans=0;
	if(k>=m){cout<<1;return;}
	int x=(m+1)/2,d=(k+1)/2;
	ans=(x-d+1)/2+1;cout<<ans<<"\n";
}

signed main(){
	ios::sync_with_stdio(false);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int u,v;cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		if(c==13||c==14){solve1();continue;}
		//solve1();return 0;
		for(int i=1;i<=n;i++)g[i].clear();
	}
}



/*
考虑先二分，然后我们就能得到每个点可达的集合
然后我们需要用k个点来覆盖所有点，且这些点至多形成2个连通块
先写个性质 
*/
