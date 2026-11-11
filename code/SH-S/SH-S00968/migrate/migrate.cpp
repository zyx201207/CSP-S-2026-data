#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5005;
int C,T,n,d,a[N],cnt[N][N],dis[N][N];
bool vis[N][N];
vector<int> g[N];
queue<int> q;
void init(){
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			vis[i][j]=cnt[i][j]=dis[i][j]=0;
	for(int i=1;i<=n;i++) g[i].clear();
} 
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>C>>T;
	while(T--){
		cin>>n>>d;
		if(n>5000){
			cout<<0<<endl;
			continue;
		}
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				if(a[j]-a[i]<=d) g[i].push_back(j);
		for(int i=1;i<=n;i++){
			q.push(i);
			dis[i][i]=1;
			while(!q.empty()){
				int u=q.front(); q.pop();
				for(int p:g[u])
					if(!dis[i][p]) dis[i][p]=dis[i][u]+1,q.push(p);
			}
		}
		for(int i=1;i<=n;i++){
			q.push(i);
			cnt[i][i]=1;
			while(!q.empty()){
				int u=q.front(); q.pop();
				vis[i][u]=true;
				for(int p:g[u]){
					if(dis[i][p]==dis[i][u]+1){
						cnt[i][p]+=cnt[i][u];
					}
					if(!vis[i][p]){
						vis[i][p]=true;
						q.push(p);
					}
				}
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++) if(cnt[i][j]==2) ans++;
		cout<<ans<<"\n";
//		for(int i=1;i<=n;i++){
//			for(int j:g[i]) cout<<j<<" ";
//			cout<<endl;
//		}
//		cout<<"\n";
//		for(int i=1;i<=n;i++){
//			for(int j=1;j<=n;j++)
//				cout<<dis[i][j];
//			cout<<endl;
//		}
//		cout<<"\n";
//		for(int i=1;i<=n;i++){
//			for(int j=1;j<=n;j++)
//				cout<<cnt[i][j];
//			cout<<endl;
//		}
		init();
	}
	return 0;
}
/*
0 1
10 3
0 3 6 7 8 9 10 11 14 17

0 4
10 14
-31 -24 -17 -10 -3 4 11 18 25 32
10 21
0 7 14 21 28 35 42 49 56 63
10 22
0 7 14 21 28 35 42 49 56 63
10 1999999999999999970
-899999999999999986 -699999999999999989 -499999999999999992 -299999999999999995 -99999999999999998 99999999999999999 299999999999999996 499999999999999993 699999999999999990 899999999999999987


0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

*/
