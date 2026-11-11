#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using xll=__int128;
const ll mxn=505,inf=1e15,mxm=5e5+7;
// struct Nd{
// 	int v,w;
// }
ll wi[mxm];
ll d[mxn][mxn];
int ids[mxm][25],did[mxm];
vector<ll> ais[mxm];
int c,n,m,mxd,q;
namespace C1{
	void ini(){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				d[i][j]=inf;
			}
			d[i][i]=0;
		}
		for(int i=1;i<=m;i++) cin>>wi[i];
		for(int i=1;i<=n;i++){
			int ki;
			cin>>ki;
			for(int j=1;j<=ki;j++){
				int aij,tij;
				cin>>aij>>tij;
				ids[aij][did[aij]++]=i;
				ais[aij].push_back(tij);
			}
		}
		ll sz=0;
		for(int i=1;i<=m;i++){
			for(int j=0;j<did[i];j++){
				int idj=ids[i][j];
				for(int k=0;k<did[i];k++){
					int idk=ids[i][k];
					if(idj!=idk){
						d[idj][idk]=d[idk][idj]=min(d[idj][idk],ais[i][j]+ais[i][k]);
					}
				}
			}
		}
		// cout<<sz<<endl;
	}
	void run(){
		// for(int i=1;i<=n;i++){
		// 	for(int j=1;j<=n;j++){
		// 		cout<<d[i][j]<<" ";
		// 	}
		// 	cout<<endl;
		// }
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					d[i][j]=d[j][i]=min(d[i][j],d[i][k]+d[k][j]);
				}
			}
		}
	}
	void out(){
		while(q--){
			int x1,x2;
			cin>>x1>>x2;
			if(x1==x2){
				cout<<0<<"\n";
			}else{
				ll mind=inf;
				for(int j=0;j<did[x1];j++){
					for(int k=0;k<did[x2];k++){
						int idj=ids[x1][j],idk=ids[x2][k];
						if(idj!=idk){
							mind=min(mind,ais[x1][j]+ais[x2][k]+d[idj][idk]);
						}else{
							mind=min(mind,ais[x1][j]+ais[x2][k]);
						}
					}
				}
				cout<<mind+wi[x1]+wi[x2]<<"\n";
			}
		}
		cout<<flush;
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>mxd>>q;
	C1::ini();
	C1::run();
	C1::out();
	return 0;
}