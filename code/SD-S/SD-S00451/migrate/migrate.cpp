#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<climits>
#include<string>
#include<algorithm>
#include<stack>
#include<queue>
#include<list>
#include<vector>
#include<map>
#include<set>
#include<utility>
using namespace std;
#define ll long long
#define pii pair<int,int>
const int N=2e6+5;
int C,T,n,d,sum[N],co[N];
ll a[N];
pii dis[N];
void dfs(int k){
	if(k==n) return ;
	for(int i=k+1;i<=n;i++){
		if(a[i]-a[k]>d) break;
		if(dis[i].first==dis[k].first+1) dis[i].second++;
		if(dis[i].first>dis[k].first+1) dis[i].first=dis[k].first+1,dis[i].second=1;
		dfs(i);
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>C>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		ll ans=0;
		for(int i=1;i<=n-3;i++){
			for(int j=i;j<=n;j++) dis[j].first=0x3f3f3f3f,dis[j].second=0;
			dis[i].first=0;
			dfs(i);
			for(int j=i;j<=n;j++) if(dis[j].second==2) ans++;
		}
		cout<<ans<<"\n";
	}
	return 0;  
}
