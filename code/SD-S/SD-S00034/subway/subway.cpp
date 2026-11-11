#include<iostream>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
const int M=5e5+5,N=505;
int c,n,m,d,q;
int w[M],k[N];
int a[3][M],t[3][M];
bool g[3][M];
long long ans;
//void dfs(int)
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	//cerr<<"w"<<endl;
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			g[i][a[i][j]]=1;
			//cerr<<i<<" "<<a[i][j]<<endl;
		}
	}
	//cerr<<"k"<<endl;
	/*if(c>=12&&c<=19){
		for(int i=1;i<=q;i++){
			cin>>x[i]>>y[i];
			ans=0;
			
		}
	}*/
	
	if(c>=20&&c<=21){
		while(q--){
			int x,y;
			cin>>x>>y;
			//cerr<<q<<" "<<x<<y<<endl;
			ans=0;
			ans+=w[x];
			ans+=w[y];
			//queue<int> q;
			//if
			//cerr<<g[1][x]<<g[1][y]<<g[2][x]<<g[2][y]<<endl;
			int minn=1000000000;
			if(g[1][x]==1&&g[1][y]==1){
				minn=min(minn,t[1][x]+t[1][y]);
				//cerr<<1<<endl;
				//cout<<ans<<endl;
				//continue;
			}
			if(g[2][x]==1&&g[2][y]==1){
				minn=min(minn,t[2][x]+t[2][y]);
				//cerr<<2<<endl;
				//cout<<ans<<endl;
				//continue;
			}
			if(g[2][x]==1&&g[2][y]==1||g[1][x]==1&&g[1][y]==1){
				cout<<ans+minn<<endl;
				continue;
			}
			for(int i=1;i<=m;i++){
				if(a[1][i]==1&&a[2][i]==1){
					minn=min(minn,t[1][i]+t[2][i]);
					//cerr<<"min"<<minn<<" "<<t[1][i]<<" "<<t[2][i]<<endl;
				}
			}
			cout<<ans+minn<<endl;
		}
		
	}
	return 0;
}
