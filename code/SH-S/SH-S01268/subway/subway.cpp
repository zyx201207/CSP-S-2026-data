#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF 1000000000000000000
struct xtt{
	int x;
	int t;
};
int c,n,m,d,q;
int w[500010]={};
xtt gx[500010][25]={};
int zlx[500010]={};
int lj[510][510]={};
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i]; 
	}
	for(int i=1;i<=n;i++){
		int k,a,t;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a>>t;
			gx[a][++zlx[a]].x=i;
			gx[a][zlx[a]].t=t;
		}
		for(int j=1;j<=n;j++){
			lj[i][j]=INF;
		}
		lj[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=zlx[i];j++){
			for(int k=j+1;k<=zlx[i];k++){
				int x1=gx[i][j].x,x2=gx[i][k].x;
				int hf=gx[i][j].t+gx[i][k].t;
				if(x1<x2)
				lj[x1][x2]=min(lj[x1][x2],hf);
				else lj[x2][x1]=min(lj[x1][x2],hf);
			}
		}
	}
	//建图完成了
	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++){
			for(int k=j+1;k<i;k++){
				lj[j][k]=min(lj[j][k],lj[j][i]+lj[k][i]);
			}
			for(int k=i+1;k<=n;k++){
				lj[j][k]=min(lj[j][k],lj[j][i]+lj[i][k]);
			}
		}
		for(int j=i+1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				lj[j][k]=min(lj[j][k],lj[i][j]+lj[i][k]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		int qd,zd;
		cin>>qd>>zd;
		int ans=INF;
		for(int j=1;j<=zlx[qd];j++){
			for(int k=1;k<=zlx[zd];k++){
				int x1=gx[qd][j].x,x2=gx[zd][k].x;
				if(x1>x2){
					int cc=x1;
					x1=x2;
					x2=cc;
				}
				ans=min(ans,gx[qd][j].t+lj[x1][x2]+gx[zd][k].t);
			}
		}
		cout<<ans+w[qd]+w[zd]<<endl;
	}
	return 0;
}



