#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
const int N=30;
int n,k;
bool G[N][N];
int dst[N];
inline void solve(){
	memset(G,0,sizeof(G));
	cin>>n>>k;
	for(int i=1,u,v;i<=n-1;i++)
		cin>>u>>v,G[u][v]=G[v][u]=1;
	int ans=n;
	for(int S=0;S<(1<<n);S++){
		if(__builtin_popcount(S)!=k)
			continue;
		int cnt=0;
		vector<int> vec;
		for(int i=0;i<n;i++)
			if((S>>i)&1){
				for(auto x:vec)
					if(G[x][i+1])
						cnt++;
				vec.push_back(i+1);
			}
		if(k!=cnt+2)
			continue;
		for(int i=1;i<=n;i++)
			dst[i]=-1;
		queue<int> q;
		for(auto x:vec)
			q.push(x),dst[x]=0;
		while(!q.empty()){
			int u=q.front();
			q.pop();
			for(int v=1;v<=n;v++)
				if(G[u][v]&&dst[v]==-1)
					dst[v]=dst[u]+1,q.push(v);
		}
		int maxx=0;
		for(int i=1;i<=n;i++)
			maxx=max(maxx,dst[i]);
		ans=min(ans,maxx);
	}
	cout<<ans<<endl;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(nullptr);
	cin.tie(0),cout.tie(0);
	int c,T;
	cin>>c>>T;
	while(T--)
		solve();
	return 0;
}
