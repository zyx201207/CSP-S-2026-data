#include<bits/stdc++.h>
#define int long long
#define db double
#define endl '\n'
#define Max(a,b,c) max(a,max(b,c))
#define Min(a,b,c) min(a,min(b,c))
#define fi first
#define se second
using namespace std;
const int N=507;
const int mod=998244353;
const int INF=1e9+7;
/*
线段树4倍，数组清空，注意longlong,优先暴力 
while(1) rp++;不犯糖 
*/
int a[N],b[N];
struct node{
	int u,v,w;
};
vector<node>f[N];
int dis[N][N],vis[N][N],vi[N][N];
void solve(){
	int n,d;
	cin>>n>>d;
	int fl=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i>2&&a[i]-a[i-1]!=a[i-1]-a[i-2]) fl=1;
	}
	if(!fl){
		int k=a[n]-a[n-1];
		int x=d/k;
		cout<<(x-1)*(n-d-1)<<endl;
		return;
	}
	if(n<=600){
			for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
			    dis[i][j]=INF;
				if(a[j]-a[i]<=d) dis[i][j]=1;
			
			}
		}
		//cout<<a[4]-a[1]<<" "<<endl;
		//cout<<dis[1][4]<<endl;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					//cout<<i<<" "<<j<<" "<<k<<" "<<endl;
					if(dis[i][j]+dis[j][k]==dis[i][k]&&!vi[i][k]){
						vis[i][k]=1;
						vi[i][k]=1;
					}else vis[i][k]=0;
					dis[i][k]=min(dis[i][k],dis[i][j]+dis[j][k]);
				}
			}
		}
    	int ans=0;
    	for(int i=1;i<=n;i++){
    		for(int j=i+1;j<=n;j++){
    			ans+=vis[i][j];
    			//if(vis[i][j]) cout<<i<<" "<<j<<endl;
    			vi[i][j]=vis[i][j]=0;
    		}
    	}
	    cout<<ans<<endl;
	    return;
	}
	cout<<(n-1)/2<<endl;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	/**/
	int T,c;
	cin>>c>>T;
	while(T--)
	    solve();
	return 0;
}/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5


*/
