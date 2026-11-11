#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5,M=505;
int n,m,d,q,w[N];
ll ans,f[M][M];
struct node{int v;ll w;};
vector<node> at[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>n>>m>>d>>q;
	for(int i=1;i<=m;++i)cin>>w[i];
	for(int i=1,x;i<=n;++i){
		cin>>x;
		for(ll j=1,y,z;j<=x;++j){
			cin>>y>>z;
			at[y].push_back({i,z});
		}
	}
	memset(f,0x3f,sizeof(f)); 
	for(int t=1;t<=m;++t){
		int len=at[t].size();
		for(int j=0;j<len;++j){
			for(int i=j+1;i<len;++i){
				f[at[t][i].v][at[t][j].v]=at[t][i].w+at[t][j].w;
				f[at[t][j].v][at[t][i].v]=at[t][i].w+at[t][j].w;
			}
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			if(i==j){f[i][j]=0;continue;}
			for(int k=1;k<=n;++k){
				if(i==k||j==k) continue;
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	while(q--){
		int s,t;
		cin>>s>>t;
		ans=1e18;
		for(int i=0;i<at[s].size();++i){
			for(int j=0;j<at[t].size();++j){
				ans=min(ans,f[at[s][i].v][at[t][j].v]+at[s][i].w+at[t][j].w);
			}
		}
		ans+=w[s]+w[t];
		cout<<ans<<"\n";
	}
	return 0;
}
