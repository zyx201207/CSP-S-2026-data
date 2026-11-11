#ifdef icop
#define nofl
#endif
#ifdef allallallall
//jimmy
//long long,momery,file,flush
#endif
#include<vector>
#include<bits/stdc++.h>
using namespace std;
constexpr int N=500,M=5e5;
constexpr long long inf=1e18;
long long g[N+5][N+5];//gragh
struct z{
	int node,w;
};
vector<z>awos[M+5];//all_way_of_solutions
int dr[M+5];//d_road
int main(){
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);
	#ifndef nofl
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	#endif
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
//		cout<<i<<"\n";
		cin>>dr[i];
//		cout<<i<<"\n";
	}
	for(int i=1;i<=n;i++){
//		cout<<i<<"\n";
		int k;
		cin>>k;
		while(k--){
//			cout<<k<<"!!\n";
//			if(k<0){
//				while(1){
//				}
//			}
			int a,t;
			cin>>a>>t;
//			cout<<a<<" "<<i<<" "<<t<<"\n"<<flush;
			awos[a].push_back(z{i,t});
//			cout<<a<<" "<<i<<" "<<t<<"\n"<<flush;
		}
		for(int j=1;j<=n;j++){
			g[i][j]=inf;
		}
		g[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<awos[i].size();j++){
			for(int k=0;k<j;k++){
				z u=awos[i][j];
				z v=awos[i][k];
				g[u.node][v.node]=min<long long>(g[u.node][v.node],1ll*u.w+v.w);
				g[v.node][u.node]=min<long long>(g[v.node][u.node],1ll*u.w+v.w);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			if(i==k){
				continue;
			}
			for(int j=1;j<=n;j++){
				if(i==j||j==k){
					continue;
				}
				g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		const vector<z> &wosx=awos[x],&wosy=awos[y];
		long long ans=inf;
		for(int i=0;i<wosx.size();i++){
			for(int j=0;j<wosy.size();j++){
				z a=wosx[i],b=wosy[j];
				ans=min(ans,g[a.node][b.node]+a.w+b.w);
			}
		}
		cout<<ans+dr[x]+dr[y]<<"\n";
	}
}
