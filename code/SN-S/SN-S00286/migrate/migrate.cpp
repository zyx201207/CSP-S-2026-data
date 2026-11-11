#include<bits/stdc++.h>
#define int long long
#define pair pair<int,int>
#define x first
#define y second
#define p 998244353
#define endl '\n'
using namespace std;
inline void read(int &x){
	x=0;
	char y=getchar();
	int z=1;
	while(y<'0'||y>'9'){
		if(y=='-'){
			z=-1;
		}
		y=getchar();
	}
	while(y>='0'&&y<='9'){
		x=(x<<1)+(x<<3)+y-'0';
		y=getchar();
	}
	x*=z;
}
bool ST;
int id,t,n,m,b[2000006],r[2000006],dp[2000006][5],tot;
pair d[12];
bool ND;
void sol(){
	read(n);
	read(m);
	for(int i=1;i<=n;i++){
		read(b[i]);
	}
	for(int i=1;i<=n;i++){
		r[i]=r[i-1];
		for(int j=r[i]+1;j<=n;j++){
			if(b[j]-b[i]>m){
				r[i]=j-1;
				break;
			}
			if(j==n){
				r[i]=n;
				continue;
			}
		}
	}
	int ans=0;
	for(int i=n;i>=1;i--){
		for(int j=1;j<=3;j++){
			dp[i][j]=0;
		}		
		if(r[i]==i){
			continue;
		}
		for(int j=1;j<=3;j++){
			int u=max(0ll,i+j-3);
			d[j].x=max(r[u],i);
		}
		for(int j=1;j<=3;j++){
			if(j==1){
				if(d[3].x==d[2].x){
					dp[i][j]=0;
				}
				else{
					dp[i][j]=d[3].x-d[2].x+dp[d[3].x][1];
				}
			}
			else if(j==2){
				if(d[3].x==d[2].x){
					dp[i][j]=0;
				}
				else{
					int u=d[3].x-d[2].x;
					dp[i][j]=dp[d[3].x][min(3ll,u+1)];
				}
			}
			else{
				if(d[1].x==d[3].x){
					dp[i][j]=0;
				}
				else{
					dp[i][j]=d[2].x-d[1].x;
					int u=d[3].x-d[2].x;
					dp[i][j]+=dp[d[3].x][min(3ll,u+1)];
				}			
			}
		}
		ans+=dp[r[i]][3];
	}
	cout<<ans<<endl;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	read(id);
	read(t);
	for(int i=1;i<=t;i++){
		sol();
	}
}
