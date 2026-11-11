#include <iostream>
#include <queue>
#include <vector>
#include <cstdio>

#define int long long

using namespace std;

const int N=510,M=5e5+10;
int w[M];
struct Node{
	int t1,t2;
}b[M];
struct edge{
	int nx,val;
};
int c,n,m,d,q;
vector<edge> g[M];
int tong[M];

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int ans=0;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>b[i].t1;
	}	
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		int lasta=0;
		for(int j=1;j<=k;j++){
			
			int a;
			cin>>a;
			tong[a]++;
			cin>>b[a].t2;
			if(j>1){
				g[a].push_back({lasta,0});
				g[lasta].push_back({a,0});
			}
			lasta=a;
		} 
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		
		ans=0;
		for(int i=1;i<=n;i++){
			ans+=tong[i]>1?b[i].t2:b[i].t1+b[i].t2;
		}
		cout<<ans<<"\n";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
