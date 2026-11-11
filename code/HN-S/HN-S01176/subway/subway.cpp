#include<bits/stdc++.h>

using namespace std;

long long n,m,d,q;

long long dij[510][510],w[500010];
int t[510][500010];
vector<int>a[500010];

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
	int c;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=500;i++){
		for(int j=1;j<=500;j++){
			dij[i][j]=LONG_LONG_MAX;
		}
		dij[i][i]=0;
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int z=1;z<=k;z++){
			cin>>c;
			cin>>t[i][c];
			for(int j=0;j<a[c].size();j++){
				int x=a[c][j];
				long long y=t[i][c]+t[x][c];
				dij[i][x]=min(dij[i][x],y);
				dij[x][i]=min(dij[x][i],y);
			}
			a[c].push_back(i);
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(dij[i][k]!=LONG_LONG_MAX&&dij[k][j]!=LONG_LONG_MAX){
					dij[i][j]=min(dij[i][j],dij[i][k]+dij[k][j]);
				}
			}
		}
	}
//	for(int i=1;i<=5;i++){
//		for(int j=1;j<=5;j++){
//			if(dij[i][j]==LONG_LONG_MAX){
//				cout<<"-1 ";
//				continue;
//			}
//			cout<<dij[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	while(q--){
		int xx,yy;
		cin>>xx>>yy;
		long long ans=LONG_LONG_MAX;
		for(int i=0;i<a[xx].size();i++){
			for(int j=0;j<a[yy].size();j++){
				ans=min(ans,w[xx]+w[yy]+dij[a[xx][i]][a[yy][j]]+t[a[xx][i]][xx]+t[a[yy][j]][yy]);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
