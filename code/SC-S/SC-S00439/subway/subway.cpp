#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q,zhan1[500050],zl,qi,z,ans,za[1000][1000],td[550];
vector<pair<int,int>>a[550],zhan[500050];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>zhan1[i];
	}
	for(int i=1;i<=n;i++){
		cin>>zl;
		td[i]=zl;
		for(int j=0;j<zl;j++){
			cin>>qi>>z;
			a[i].push_back({qi,z});
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=td[k];i++){
			for(int j=i+1;j<=td[k];j++){
				za[a[k][i-1].first][a[k][j-1].first]=a[k][i-1].second+a[k][j-1].second;
				za[a[k][j-1].first][a[k][i-1].first]=a[k][i-1].second+a[k][j-1].second;
			}
		}
	}
	for(int k=1;k<=m;k++){
		for(int i=1;i<=m;i++){
			for(int j=i+1;j<=m;j++){
				if(za[i][k]!=0&&za[k][j]!=0){
					if(za[i][j]==0){
						za[i][j]=max(za[i][j],za[i][k]+za[k][j]);
						za[j][i]=za[i][j];
					}
					else{
						za[i][j]=min(za[i][j],za[i][k]+za[k][j]);
						za[j][i]=za[i][j];
					}
					//cout<<i<<" "<<j<<" "<<k<<" "<<za[i][j]<<endl;
				}
			}
		}
	}
	for(int i=1;i<=q;i++){
		cin>>qi>>z;
		cout<<za[qi][z]+zhan1[qi]+zhan1[z]<<endl;
	}
	return 0;
}