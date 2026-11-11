#include<bits/stdc++.h>
using namespace std;
const long long N=2e4+555;
long long ww[N],n,m,d,Q,c,cnt;
int dis[N][N];
inline long long read(){
	char x=getchar();
	long long f=1,ans=0;
	while(x<'0'||x>'9'){
		if(x=='-')
			f=-1;
		x=getchar();
	}
	while(x<='9'&&x>='0'){
		ans=ans*10+x-'0';
		x=getchar();
	}
	return ans*f;
}
void dij(){
	for(long long k=1;k<=m+n+1;k++){
		for(long long i=1;i<=m+n+1;i++){
			for(long long j=1;j<=m+n+1;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(),n=read(),m=read(),d=read(),Q=read();
	for(long long i=1;i<=m;i++)
		ww[i]=read();
	for(long long i=1;i<=m+n+1;i++){
		for(long long j=1;j<=m+n+1;j++)
			dis[i][j]=0x3f3f3f3f;
		dis[i][i]=0;
	}
	for(long long i=1;i<=n;i++){
		long long T=read();
		while(T--){
			long long v=read(),w=read();
			dis[v][i+m]=dis[i+m][v]=w;
		}
	}
	dij();
	while(Q--){
		long long x=read(),y=read();
		cout<<dis[x][y]+ww[x]+ww[y]<<"\n";
	}
	return 0;
} 
/*
Oct31==Dec25?
*/
