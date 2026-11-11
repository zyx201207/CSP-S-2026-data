#include<bits/stdc++.h>
using namespace std;
#define MAXN 5010
#define int long long
typedef long long ll;
ll n,d,x[MAXN],ccc,T;
int dis[MAXN][MAXN],cnt[MAXN][MAXN],ans;

inline void read(ll& x){
	char ch=getchar();int f=1;x=0;
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=-1;
	for(;isdigit(ch);ch=getchar())x=(x<<3)+(x<<1)+(ch^48);
	x*=f;
}

void init(){
	for(int i=1;i<=n;i++)
	    for(int j=i+1;j<=n;j++){
	    	if(i==j)dis[i][j]=0;
	        else dis[i][j]=INT_MAX;
	        cnt[i][j]=0;
		}
	for(int u=1;u<=n;u++)
		for(int v=u+1;v<=n;v++)
		    if(x[v]-x[u]<=d){
		    	dis[u][v]=1;
//		    	cnt[u][v]=1;
			}
	ans=0;
}

void solve1(){
	for(int k=1;k<=n;k++)
	    for(int i=1;i<k;i++){
	    	if(dis[i][k]==INT_MAX)continue;
	    	for(int j=k+1;j<=n;j++){
	    		if(dis[k][j]==INT_MAX)continue;
	    		ll nd=dis[i][k]+dis[k][j];
	    		if(dis[i][j]>nd){
	    			dis[i][j]=nd;
	    			cnt[i][j]=1;
				}else if(dis[i][j]==nd)
					cnt[i][j]++;
			}
		}
	for(int i=1;i<=n;i++)
	    for(int j=i+1;j<=n;j++)
	        if(dis[i][j]!=INT_MAX&&cnt[i][j]==2){
	        	ans++;//debug(i);debug(j);debug(dis[i][j]);
			}
	cout<<ans<<endl;
}

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	read(ccc);read(T);
	while(T--){
		read(n);read(d);
		for(int i=1;i<=n;i++)read(x[i]);
		init();
		solve1();
	}
	return 0;
}
