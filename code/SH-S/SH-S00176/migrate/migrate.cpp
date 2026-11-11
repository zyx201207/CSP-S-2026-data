#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int c,t,z[N];
queue<int>q;
vector<int>v[N];
int vis[N],dis[N];
void solve(){
	//多测清空
	while(t--){
		int n,d;
		//岛屿数量，海鸟一次最多飞行的距离
		cin>>n>>d;
		int sum=0;
		memset(z,0,sizeof z);
		for(int i=1;i<=n;i++)v[i].clear();
		memset(vis,0,sizeof vis);
		for(int i=1;i<=n;i++)cin>>z[i];//每座岛屿的坐标
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if((z[i]+d)>=z[j])v[i].push_back(j);
			}
		}
		for(int i=1;i<=n;i++){
			q.push(i);
			memset(vis,0,sizeof vis);
			vis[i]=1;
			for(int j=1;j<=n;j++)dis[j]=1e18;
			dis[i]=0;
			while(!q.empty()){
				int k=q.front();
				q.pop();
				for(int j=0;j<v[k].size();j++){
					int to=v[k][j];
					int sum=dis[k]+1;
					if(!vis[to]){
						vis[to]=vis[k];
						dis[to]=sum;
						q.push(to);
					}else if(dis[to]==sum){
						vis[to]+=vis[k];
					}
				}
			}
			for(int j=1;j<=n;j++){
				if(vis[j]==2)sum++;
			}
		} 
		cout<<sum<<'\n';
	} 
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	solve();
	return 0;
}
