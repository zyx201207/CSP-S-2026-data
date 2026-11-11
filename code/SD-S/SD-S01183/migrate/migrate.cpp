#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>
#define int long long
using namespace std;
typedef pair<int,int> P;
const int N=2e6+5;
int n,d;
int x[N];
int dis[N],cnt[N];
vector<int> v[N];
queue<int> q;
inline void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;i++) cin>>x[i],v[i].clear();
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			if(x[j]-x[i]<=d){
//				cout<<i<<" "<<j<<"\n";
				v[i].emplace_back(j);
				v[j].emplace_back(i);
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) dis[j]=0x3f3f3f3f,cnt[j]=0;
		q.emplace(i);
		dis[i]=0;
		cnt[i]=1;
		while(!q.empty()){
			int x=q.front(); q.pop();
			for(int j:v[x]){
//				cout<<x<<" "<<j<<"\n";
				if(dis[j]>dis[x]+1){
					dis[j]=dis[x]+1;
					cnt[j]=1;
					q.emplace(j);
				}
				else if(dis[j]==dis[x]+1){
					cnt[j]++;
					q.emplace(j);
				}
			}
		}
//		cout<<i<<" ";
		for(int j=1;j<=n;j++){
//			cout<<cnt[j]<<" ";
			if(cnt[j]==2) ans++;
		}
//		cout<<"\n";
	}
	cout<<ans/2<<"\n";
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	int c,T=1;
	cin>>c>>T;
	while(T--) solve();
	return 0;
}
