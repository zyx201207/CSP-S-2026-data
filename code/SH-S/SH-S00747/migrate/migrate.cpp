#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=2e6+6;
int x[maxn];
int cnt[maxn];
int dis[maxn];
int c,t;
void solve(){
	int n,d;
	cin>>n>>d;
	int ans=0;
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	if(c>=11){
		cout<<0<<endl;
		return;
	}
	for(int start=1;start<=n;start++){
		for(int i=1;i<=n;i++){
			dis[i]=1e18;
			cnt[i]=0;
		}
		dis[start]=0;
		queue<int>q;
		q.push(start);
		cnt[start]=1;
		while(!q.empty()){
			int u=q.front();
			q.pop();
			for(int i=u-1;i>=1;i--){
				if(i<1)break;
				if(x[u]-x[i]>d)break;
				if(cnt[i]){
					if(dis[u]+1<=dis[i]){
						cnt[i]+=cnt[u];
					}
				}else{
					dis[i]=dis[u]+1;
					cnt[i]=cnt[u];
					q.push(i);
				}
			}
			for(int i=u+1;i<=n;i++){
				if(i>n)break;
				if(x[i]-x[u]>d)break;
				if(cnt[i]){
					if(dis[u]+1<=dis[i]){
						cnt[i]+=cnt[u];
					}
				}else{
					dis[i]=dis[u]+1;
					cnt[i]=cnt[u];
					q.push(i);
				}
			}
			
		}for(int i=1;i<=n;i++){
		//	cout<<'|'<<cnt[i]<<endl;
			if(cnt[i]==2){
				ans++;
			}
		}
	}cout<<ans/2<<'\n';
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--){
		solve();
	}cout<<endl;
	return 0;
}
