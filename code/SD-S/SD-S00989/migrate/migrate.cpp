#include<bits/stdc++.h>
using namespace std;
//#define int long long
const int N=2e6+10;
int c,n;
long long d;
int vis[N],cnt[N];
long long a[N];
int dis[N];
vector<pair<int,int> > g[N];
void dfs(int x,int s){
//	cout<<x<<" "<<dis[x]<<" "<<cnt[x]<<"\n";//<<" "<<s1<<" "<<s2<<"£¡\n";
	for(auto i:g[x]){
		int u=i.first;
		if(u<x) continue;
		if(dis[u]==s) cnt[u]+=cnt[x] ;//,cout<<x<<":"<<cnt[x]<<"\n";
		else if(dis[u]>s){
//			if(u==6) cout<<x<<":"<<cnt[x]<<"\n";
			cnt[u]=cnt[x];
			dis[u]=s;
		}
		if(dis[u]==s) dfs(u,s+1); 
	} 
	return ;
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
	int _;
	cin>>c>>_;
	while(_--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		if(c<=10){
			for(int i=1;i<=n;i++) g[i].clear();
			for(int i=1;i<n;i++){
				for(int j=i+1;j<=n;j++){
					if(a[j]-a[i]>d) break;
					g[i].push_back({j,1});
					g[j].push_back({i,1});
			//		cout<<i<<"->"<<j<<"\n";
				}
			}
			int ans=0;
			for(int i=1;i<n;i++){
				for(int j=i+1;j<=n;j++) dis[j]=INT_MAX,cnt[j]=0;
				cnt[i]=1,dis[i]=0;
				dfs(i,1);
			//	for(int j=i+1;j<=n;j++) cout<<j<<" "<<dis[j]<<" "<<cnt[j]<<"!\n";
				for(int j=i+1;j<=n;j++){
				//	int cn=dfs(i,j,0,dis[j]);
//					cout<<i<<" "<<j<<" "<<dis[j]<<" "<<cnt[j]<<"\n";
					if(cnt[j]==2) ans++;
				}
			}
		//	cout<<"!\n";	
			cout<<ans<<"\n";
		}
		
	}
	return 0;
}
/*
0 1
7 666666666666666663
-1000000000000000000 -555555555555555558 -111111111111111116 111111111111111105 333333333333333326 555555555555555547 999999999999999989

*/
