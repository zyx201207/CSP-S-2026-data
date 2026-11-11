#include<bits/stdc++.h>
#define int long long
using namespace std;
int read(){
	int x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();
	return x*f;
}
const int N=5005,inf=1e18;
int n,d,x[2000005],ans;
int dis[N][N],way[N][N];
void solve(){
	n=read(),d=read(),ans=0;
	for(int i=1;i<=n;i++) x[i]=read();
	for(int i=2;i<=n;i++)
		for(int j=i-1;j>=1;j--){
			if(x[i]-x[j]>d) dis[j][i]=inf;
			else dis[j][i]=1;
			way[j][i]=1;
		}
	for(int i=1;i<n;i++)
		for(int j=i+1;j<=n;j++){
			for(int k=i+1;k<=j-1;k++){
				int d=dis[i][k]+dis[k][j];
				if(d==dis[i][j]) way[i][j]+=way[i][k]*way[k][j];
				else if(d<dis[i][j]) dis[i][j]=d,way[i][j]=way[i][k]*way[k][j];
			}
			if(way[i][j]==2) ans++;
		}
	printf("%lld\n",ans);
}
void solve2(){
	n=read(),d=read();
	for(int i=1;i<=n;i++) x[i]=read();
	if((x[2]-x[1])*2>d){ puts("0"); return; }
	int a=d/(x[2]-x[1]);
	printf("%lld\n",max(0ll,n-2*a+1));
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c=read(),t=read();
//	if(c<=10) while(t--) solve();
//	else 
	while(t--) solve2();
	return 0;
}
/*
I saw the wild  flowers dying
as they froze  in the winter
lost my clothes  in the water
feel the sand  between my toes
all these days  we keep trying
put our hands  on the lion
never thought  we stop flying
just to walk this on our own
oh we are growing old now
will it ever be the same
since we slow down
we slow down
we slow down
we slow down
slow down
we slow down
down down down
we slow down
*/
