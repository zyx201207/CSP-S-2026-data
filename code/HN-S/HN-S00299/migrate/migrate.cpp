#include <bits/stdc++.h>

#define pb push_back
#define fst first
#define sec second

using namespace std;

using ll = long long;
using ull =unsigned long long;
using i128 = __int128;
using p_q =priority_queue<int>;

namespace sharweek{

const int N = 4e5+5;

ll dis[N],f[N],x[N];
bool vis[N];
int q[N];
int hd=1,tl=0;
vector<int> g[N];

void mian(){
	int n;ull d,ans=0;cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(i128(x[j])-i128(x[i])>d) break;
			g[j].pb(i);
			g[i].pb(j);
		}
	}
	
	for(int i=1;i<=n;i++) f[i]=0,vis[i]=0,dis[i]=1e9;
	
	for(int s=1;s<=n;s++){
		hd=1,tl=0;
		q[++tl]=s;dis[s]=0,f[s]=1;
		while(hd<=tl){
			int u=q[hd++];
			if(vis[u]) continue;
			vis[u]=1;
			for(int v:g[u]){
				if(vis[v]) continue;
				if(dis[v]==dis[u]+1){
					f[v]+=f[u];
				}
				if(dis[v]>dis[u]+1){
					dis[v]=dis[u]+1,f[v]=f[u];q[++tl]=v; 
				}
			}
		}
		/*cout<<s<<":";
		for(int i=1;i<=n;i++) cout<<f[i]<<" ";
		cout<<endl;*/
		
		for(int i=1;i<=n;i++){
			if(f[i]==2) ans++;
		}
		
		for(int i=1;i<=n;i++) f[i]=vis[i]=0,dis[i]=1e9;
	}
	cout<<(ans>>1)<<"\n";
	
	for(int i=1;i<=n;i++) g[i].clear();
}

}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	int c,_=1;
	cin>>c>>_;
	while(_-->0){
		sharweek::mian();
	}
	
	return 0;
} 

/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/
