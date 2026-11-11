#include<bits/stdc++.h>
using namespace std;
int dis[1010][1010],w[500010];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
		memset(dis,0x3f,sizeof(dis));
		for(int i=1;i<=m;++i){
			cin>>w[i];dis[i][i]=0;
		}
		for(int i=1;i<=n;++i){
			int k;cin>>k;
			if(k==1){
				cin>>k>>k;
			}else{
				vector<int> ac,bc;
				for(int j=1;j<=k;++j){
					int a,b;
					cin>>a>>b;
					for(int kk=0;kk<ac.size();++kk){
						dis[ac[kk]][a]=bc[kk]+b;dis[a][ac[kk]]=bc[kk]+b;
					}
					ac.push_back(a);bc.push_back(b);
				}
			}
		}
		for(int k=1;k<=m;++k)
			for(int i=1;i<=m;++i){
				for(int j=1;j<=m;++j){
					dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
				}
			}
		while(q--){
			int x,y;
			cin>>x>>y;
			cout<<w[x]+w[y]+dis[x][y]<<"\n";
		}// havenottime
	return 0;
} 
