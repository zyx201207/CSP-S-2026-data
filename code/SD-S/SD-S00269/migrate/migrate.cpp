#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
const int N=2e6+5,D=25;
const int M=2e6+5;
int a[N];
int n,d;
namespace pts10{
	const int sn=5005;
	vector<int> v[N];
	int dis[sn];
	queue<int> q;
	int vis[sn];
	int good[N];
	int bfs(int qwer){
		vis[qwer]=1;
		for(int i=1;i<=n;i++) good[i]=0;
		q.push(qwer);
		int ans=0;
		while(!q.empty()){
			int t=q.front();q.pop();
			for(auto i:v[t]){
				if(vis[i]==2) continue;
				if(dis[i]==dis[t]+1) good[i]++;
				dis[i]=min(dis[i],dis[t]+1);
				q.push(i);
				vis[i]++;
			}
		}
		for(int i=1;i<=n;i++){
			if(good[i]==1) ans++;
		}
		return ans;
	}
	void solve(){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(i==j) continue;
				int td=abs(a[i]-a[j]);
				if(d>=td){
					v[i].push_back(j);
					v[j].push_back(i);
				}
			}
		}
		int anss=0;	
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j) dis[j]=0;
				else dis[j]=1e18;
				vis[j]=0;
			} 
			anss+=bfs(i);
		}
		cout<<anss/2<<endl;
	}	
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		pts10::solve();
	}
	return 0;
} 
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6



0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/
