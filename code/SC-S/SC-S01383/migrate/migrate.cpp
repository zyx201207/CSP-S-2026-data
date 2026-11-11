#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1000005;
const ll INF=0x3f3f3f3f3f3f3f3f;
int C,T,n;
ll d,x[N],dis[305][305],cnt[305][305];
inline bool check(){
	if(n>300) return false;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			dis[i][j]=(i==j?0:(abs(x[i]-x[j])<=d?1:INF));
			cnt[i][j]=1;
		}
	}
	for(int k=1;k<=n;++k){
		for(int i=1;i<=n;++i){
			if(i==k) continue;
			if(dis[i][k]==INF) continue;
			for(int j=1;j<=n;++j){
				if(i==j||j==k) continue;
				if(dis[k][j]==INF) continue;
				ll res=dis[i][k]+dis[k][j];
				ll tmp=cnt[i][k]*cnt[k][j];
				if(res<dis[i][j]){
					dis[i][j]=res;
					cnt[i][j]=tmp;
				}else if(res==dis[i][j])
					cnt[i][j]+=tmp;
			}
		}
	}
//	for(int i=1;i<=n;++i){
//		for(int j=1;j<=n;++j){
//			cout<<"\n-----\n";
//			cout<<i<<' '<<j<<'\n';
//			cout<<dis[i][j]<<' '<<cnt[i][j]<<'\n';
//			cout<<"\n-----\n";
//		}
//	}
	int ans=0;
	for(int i=1;i<=n;++i){
		for(int j=i+1;j<=n;++j){
			if(cnt[i][j]==2)
				++ans;
		}
	}
	cout<<ans<<'\n';
	return true;
}
inline void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;++i)
		cin>>x[i];
	if(check()) return ;
	cout<<"0\n";
	return ;
}
//Небо 
signed main(){
//	freopen("migrate4.in","r",stdin);
//	freopen("my.out","w",stdout);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>C>>T;
	while(T--)
		solve();
	return 0;
}