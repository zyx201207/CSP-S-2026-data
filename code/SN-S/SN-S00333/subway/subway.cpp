//李方骁 西安交通大学附属中学 SN-S00333
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int c,n,m,d,q;
int w[500005];
int k[505],a[505][20005],t[505][20005];
ll apt,aa[500005],tt[3][500005];//20 21
int x,y;
ll mimi=1e18;

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i){
		cin>>w[i];
	}
	if(c==20 or c==21){
		for(int i=1;i<=n;++i){
			cin>>k[i];
			for(int j=1;j<=k[i];++j){
				cin>>apt>>tt[i][j];
				aa[apt]+=i;
				if(aa[apt]==3){
					mimi=min(mimi,tt[1][apt]+tt[2][apt]);
				}
			}
		}
		while(q--){
			cin>>x>>y;
			if(n==1){
				cout<<w[x]+w[y]+tt[1][x]+tt[1][y];
			}
			else{
				if(aa[x]==1 and aa[y]==1){
					cout<<w[x]+w[y]+tt[1][x]+tt[1][y];
				}
				else if(aa[x]==2 and aa[y]==2){
					cout<<w[x]+w[y]+tt[2][x]+tt[2][y];
				}
				else if(aa[x]==1 and aa[y]==2){
					cout<<w[x]+w[y]+tt[1][x]+tt[2][y]+mimi;
				}
				else if(aa[x]==2 and aa[y]==1){
					cout<<w[x]+w[y]+tt[2][x]+tt[1][y]+mimi;
				}
				else if(aa[x]==3 and aa[y]==3){
					cout<<min(min(w[x]+w[y]+tt[1][x]+tt[1][y],w[x]+w[y]+tt[2][x]+tt[2][y]),min(w[x]+w[y]+tt[1][x]+tt[2][y]+mimi,w[x]+w[y]+tt[2][x]+tt[1][y]+mimi));
				}
				else if(aa[y]==3){
					cout<<min(w[x]+w[y]+tt[aa[x]][x]+tt[aa[x]][y],w[x]+w[y]+tt[aa[x]][x]+tt[3-aa[x]][y]+mimi);
				}
				else if(aa[x]==3){
					cout<<min(w[x]+w[y]+tt[aa[y]][x]+tt[aa[y]][y],w[x]+w[y]+tt[3-aa[y]][x]+tt[aa[y]][y]+mimi);
				}
			}
			cout<<'\n';
		}
	}
	else{
		for(int i=1;i<=n;++i){
			cin>>k[i];
			for(int j=1;j<=k[i];++j){
				cin>>a[i][j]>>t[i][j];
			}
		}
//		if(c>=7 and c<=11){
//			for(int i=1;i<=m;++i){
//				
//			}
//		}
		while(q--){
			cin>>x>>y;
			cout<<w[x]+w[y]<<'\n';
		}
	}
	
	return 0;
}
