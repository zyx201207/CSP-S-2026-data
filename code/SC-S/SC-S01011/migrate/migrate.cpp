#include<bits/stdc++.h>
#define int long long
using namespace std;
using ll=long long;
const int N=2e6+5;
int c,T,n;
ll a[N],d,dis[N],cnt[N];
unordered_map<ll,int> mp;
void solve(){
	ll ans=0;
	memset(dis,0,sizeof dis);
	for(int i=1;i<=n;++i){
		memset(cnt,0,sizeof cnt);
		mp.clear();
		dis[i]=0;
		int l=i,r=i;mp[dis[i]]=1;
		deque<int> q;
		q.push_back(i);
		for(int j=i-1;j>0;--j){
//			cout<<"i,j="<<i<<" "<<j<<"\n";
			while(!q.empty()&&a[q.back()]-a[j]>d)
				q.pop_back();
			while(l<=r&&a[r]-a[j]>d){
				mp[dis[r]]-=cnt[r];
				--r;
			}
			if(l>r)break;
			dis[j]=dis[q.back()]+1;
			if(mp[dis[q.back()]]==2){
				++ans;
			}
//			cout<<mp[dis[q.back()]]<<" "<<dis[q.back()]<<"\n";
			cnt[j]=mp[dis[q.back()]];
			mp[dis[j]]+=cnt[j];--l;
			while(!q.empty()&&dis[j]<=dis[q.front()])
				q.pop_front();
			q.push_front(j);
		}
	}
	cout<<ans<<"\n";
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;++i)cin>>a[i];
//		ini();
		solve();
	}
	return 0;
}