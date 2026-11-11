#include<bits/stdc++.h>
using namespace std;
const int N=520,M=5e5+10;
int c,n,m,d,q,t2[M][21],l[M];
long long w[M],f[N][N],t[M][21];
int main(){
	freopen("subway.in","r",stdin),freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)scanf("%lld",&w[i]);
	for(int i=0,k;i<n;i++){
		for(int j=0;j<n;j++)f[i][j]=1e18;
		scanf("%d",&k),f[i][i]=0;
		for(int j=0,x;j<k;j++)scanf("%d",&x),t2[x][l[x]]=i,scanf("%lld",&t[x][l[x]++]);
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<l[i];j++){
			for(int k=0;k<l[i];k++){
				f[t2[i][j]][t2[i][k]]=min(f[t2[i][j]][t2[i][k]],t[i][j]+t[i][k]);
			}
		}
	}
	for(int k=0;k<n;k++){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++)f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
		}
	}
	while(q--){
		int x,y;
		long long ans=1e18;
		scanf("%d%d",&x,&y);
		for(int i=0;i<l[x];i++){
			for(int j=0;j<l[y];j++)ans=min(ans,t[x][i]+f[t2[x][i]][t2[y][j]]+t[y][j]);
		}
		printf("%lld\n",ans+w[x]+w[y]);
	}
}