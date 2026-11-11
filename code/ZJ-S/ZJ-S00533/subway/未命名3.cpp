#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,mn=0x3f3f3f,w[500500],k[550],a[550][5500],x[10086],y[10086];
int mp[500500][30],mp1[500500][30],t[550][5500],p[5500][5500];
//c：编号，n：地铁线数，m地铁站数，d站点经过最多线数
//q计划数，p站间最小值 ，mp站点对应下一站 ,a
int v[500500];
void e(int x){
	for(int i=1;i<=mp[x][0];i++){
		for(int j=1;j<k[mp[x][i]];j++){
			p[x][a[i][j]]=min(p[x][a[i][j]],t[i][j]+t[i][mp1[x][i]]);
		}
	}
}
int f(int x,int y){
	for(int i=1;i<=m;i++){
		if(v[i]==0){
			v[i]=1;
			p[x][y]=min(p[x][y],f(x,i)+f(i,x));
			v[i]=0;
		}
	}return p[x][y];
}
int main(){
	//freopen("subway.in","r",stdin);
	//freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i];
	}
	memset(p,0x3f3f3f,sizeof(p));
	for(int i=0;i<=n;i++){
		for(int j=1;j<=k[i];j++){
			mp[a[i][j]][0]++;
			mp[a[i][j]][mp[a[i][j]][0]]=i;
			mp1[a[i][j]][mp[a[i][j]][0]]=j;
		}
	}
	for(int i=1;i<=m;i++){
		e(i);
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			for(int k=1;k<=m;k++){
				p[i][j]=min(p[i][j],p[i][k]+p[k][j]);
			}
		}
	}cout<<q;
	for(int i=1;i<=q;i++){
		cout<<p[x[i]][y[i]]<<endl;
	}
}
