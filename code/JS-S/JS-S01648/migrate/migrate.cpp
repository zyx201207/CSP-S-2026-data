#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int o;
int a[200010];
int dis[200010];
int cnt[200010];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cout.tie(0),cin.tie(0);
	cin>>o>>o;
	while(o--){
		ll ans=0;
		int n,m;
		cin>>n>>m;
		vector<int> v[200010];
		for(int i=1;i<=n;i++){
			cin>>a[i];
			for(int j=i-1;j>0;j--){
				if(a[i]-a[j]<=m){
					v[i].push_back(j);
					v[j].push_back(i);
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++) dis[j]=0;
			queue<int> q;
			q.push(i);
			dis[i]=1,cnt[i]=1;
			while(q.size()){
				int d=q.front();
				q.pop();
				for(int x:v[d]){
					if(dis[x]){
						if(dis[x]==dis[d]+1) cnt[x]+=cnt[d];
						continue;
					}else{
						cnt[x]=cnt[d];
						q.push(x);
						dis[x]=dis[d]+1;
					}
				}
			}
			for(int j=i+1;j<=n;j++) if(cnt[j]==2) ans++;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
