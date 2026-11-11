#include<bits/stdc++.h>
using namespace std;
const int N=1e6+7;
int n,m,c,d,q,x,y,w;
int o,zix[N][N],zj[N][N],zk[N][N],zdsj[N],sj,ft,k2,k;
int a[N],b[N],t[N];
void bil(int x,int y){
	if(x==y or zk[x][0]==0){
		o--;
		return 0;
	}
	for(int k=1,k2=1;k2<=zk[x][0];k++){
		if(zk[x][k]==0)continue;
			k2++;
			//分叉
			//fch(t,x,y,xs);
			zj[o][k2+zj[o][0]]=zdsj[x]+sj[zk[x][k]+1];
			ft[o][k2+zj[o][0]]=x;
		//	time=time+zdsj[x]+sj[j];
	}zj[o][0]=k2;
	o++;
	for(int i=1,j=1;j<=zk[x][0];i++){
		if(zk[x][k]==0)continue;
		bil(zk[x][k]+1,y);
	}
}
int main(){
	freopen("subway.in","w",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w;
		sj[i]=w;
	}for(int i=1;i<=n;i++){
		cin>>k;//第 i 条线路经过的地铁站数；
		xl[i][0]=k;
		for(int j=1;j<=k;j++){
			cin>>a>>t;
			xl[i][j]=a;
			zk[a][i]=j;//站口a是第i线路的第j站 
			zk[a][0]++;//有a【0】条线过a站 
			zdsj[i]=t;//该地铁站的站厅走到第 i 条线
		}
	}while(q--){
		cin>>x>>y;
		bil(x,y);
		for(int i=1;i<=o;i++){
			for(int j=1;j<=zj[o][0];j++){
				zzda=
			}if(zzda[i]<zx)zx=zzda[i];
		}
		cout<<zx<<endl;
		
	}
	return 0;
}
	
