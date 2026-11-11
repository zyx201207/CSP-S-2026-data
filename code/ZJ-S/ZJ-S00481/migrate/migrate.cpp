#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int c,t,n,f[N][25],g[N][25];
long long d,x[N],ans;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>x[i];
		for(int i=1,j=1;i<=n;i++){
			while(j<=n&&x[j]-x[i]<=d)++j;
			f[i][0]=j-1;
		}
		for(int i=n,j=n;i>=1;i--){
			while(j&&x[i]-x[j]<=d)--j;
			g[i][0]=j+1;
		}
		for(int j=1;j<=21;j++)for(int i=1;i<=n;i++)f[i][j]=f[f[i][j-1]][j-1],g[i][j]=g[g[i][j-1]][j-1];
		for(int i=1;i<=n;i++)for(int j=i+2;j<=n;j++){
			int kmax=min(21,(int)floor(log2(j-i))+1);
			int ii=i,jj=j;
			if(f[i][0]>j||g[j][0]<i)continue;
			for(int k=kmax;k>=0;k--)if(f[ii][k]<=g[jj][k])ii=f[ii][k],jj=g[jj][k];
			if(f[ii][0]==jj+1||g[jj][0]==ii+1){
				++ans;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*
0 2
5 3
-2 -1 0 1 2

*/

