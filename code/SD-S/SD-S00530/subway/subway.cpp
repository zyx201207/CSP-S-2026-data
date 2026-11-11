#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=505,M=5e5+10,inf=4e18;
int f[N][N],koyuki,n,m,d,q,w[M];
vector<pii> vec[M];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	memset(f,0x3f,sizeof f);
	cin>>koyuki>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1,len;i<=n;i++){
		cin>>len;
		for(int j=1,u,t;j<=len;j++){
			cin>>u>>t;
			vec[u].push_back({t,i});
		}
	}
	for(int u=1;u<=m;u++){
		for(auto va:vec[u]){
			for(auto vb:vec[u]){
				int uua=va.second,uub=vb.second,val=va.first+vb.first;
				if(uua==uub)continue;
				f[uua][uub]=min(f[uua][uub],val);
				f[uub][uua]=min(f[uub][uua],val);
			}
		}
	}
	for(int i=1;i<=n;i++)f[i][i]=0;
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(f[i][k]>inf||f[k][j]>inf)continue;
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]); 
			}
		}
	}
	while(q--){
		int u,v;cin>>u>>v;
		int ans=inf;
		for(auto i:vec[u]){
			for(auto j:vec[v]){
				int val=i.first+j.first;
				int uua=i.second,uub=j.second;
				ans=min(ans,val+w[u]+w[v]+f[uua][uub]);
			}
		}cout<<ans<<"\n";
	}
	return 0;
}
