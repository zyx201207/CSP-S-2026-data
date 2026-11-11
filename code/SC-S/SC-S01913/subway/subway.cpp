#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q,ans;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	int tm1[10000],xl[100][100],tm2[100][100];
	for(int i=1;i<=m;i++){
		cin>>tm1[i];
	} 
	int mxx=-1e9;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		if(x>mxx) mxx=x;
		for(int j=1;j<=x;j++){
			cin>>xl[i][j];
			cin>>tm2[i][j];
		}
	}
	
	for(int i=1;i<=q;i++){
		ans=0;
		int x,y;
		int nxl,njj;
		cin>>x>>y;
		for(int ii=1;ii<=n;ii++){
			for(int jj=1;jj<=mxx;jj++){
				if(xl[ii][jj]==x){
					nxl=ii;
					njj=jj;
				}
			}
		}
		ans+=tm1[nxl];
		ans+=tm2[nxl][njj];
		int mx=1e9,mxi=0,mxj=0;
		for(int ii=1;ii<=n;ii++){
			for(int jj=1;jj<=mxx;jj++){
				if(xl[ii][jj]-y<mx){
					mx=xl[ii][jj]-xl[nxl][njj];
					mxi=ii,mxj=jj;
				}
				if(xl[ii][jj]>y){
					break;
				} 
				 
			}
			ans+=tm1[xl[mxi][mxj]];
			ans+=tm2[mxi][mxj];
		}
		cout<<ans<<endl;
	}
	
	return 0;
}