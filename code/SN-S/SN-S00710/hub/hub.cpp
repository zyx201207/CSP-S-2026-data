#include<bits/stdc++.h>
#define int long long
using namespace std;
namespace zhu{bool ST;
int c,T,n,K,fa[1001000],mp[11][11];
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
bool ED;string main(){
	cin>>c>>T;
	while(T--){
		cin>>n>>K;
		memset(mp,0x3f,sizeof mp);
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			mp[u][v]=mp[v][u]=1;
		}
		for(int i=1;i<=n;i++) mp[i][i]=0;
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					mp[i][j]=min(mp[i][j],mp[i][k]+mp[k][j]);
				}
			}
		}
		int ans=1e18;
		for(int S=0;S<(1ll<<n);S++){
			int cnt=0;
			for(int i=1;i<=n;i++) if((S>>(i-1))&1) cnt++;
			if(cnt!=K) continue;
			for(int i=1;i<=n;i++) fa[i]=i;
			for(int i=1;i<=n;i++){
				if(!((S>>(i-1))&1)) continue;
				for(int j=1;j<=n;j++){
					if(!((S>>(j-1))&1)) continue;
					if(mp[i][j]!=1) continue;
					fa[find(j)]=find(i);
				}
			}
			int num=0;
			for(int i=1;i<=n;i++){
				if(((S>>(i-1))&1)&&fa[i]==i) num++;
			}
			if(num>2) continue;
//			cout<<num<<"\n";
			int mx=0;
			for(int i=1;i<=n;i++){
				int mn=1e18;
				for(int j=1;j<=n;j++) if((S>>(j-1))&1) mn=min(mn,mp[i][j]);
//				cout<<mn<<"\n";
				mx=max(mx,mn);
			}
			ans=min(ans,mx);
		}
		cout<<ans<<"\n";
	}
	return ".";
}
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin.tie(0);cout.tie(0);
	ios::sync_with_stdio(0);
	cerr<<zhu::main()<<'\n'<<(&zhu::ST-&zhu::ED)/1048576.0;
}
/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10
*/
