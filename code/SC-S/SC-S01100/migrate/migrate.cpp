#include<bits/stdc++.h>
using namespace std;
long long a[2000005],b[305];
vector<int>g[305];
void solve300(int t){
	while(t--){
		int n;
		long long d,ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)g[i].clear();
		for(int i=1;i<=n;i++){
			cin>>b[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(b[j]-b[i]>d)continue;
				g[i].push_back(j);
			}
		}for(int i=1;i<=n;i++){
			vector<int>dis(n+5,1e9);
			dis[i]=0;
			vector<int>cnt(n+5);
			cnt[i]=1;
			queue<int>q;
			q.push(i);
			while(!q.empty()){
				int u=q.front();
				q.pop();
				for(auto v:g[u]){
					if(dis[v]>dis[u]+1){
						dis[v]=dis[u]+1;
						cnt[v]=cnt[u];
						q.push(v);
					}else if(dis[v]==dis[u]+1){
						cnt[v]+=cnt[u];
					}
				}
			}for(int j=i+1;j<=n;j++){
				if(cnt[j]==2)ans++;
			}
		}cout<<ans<<'\n';
	}
}void solveA(int t){
	while(t--){
		int n;
		long long d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}if(n<=3){
			cout<<0<<'\n';
			continue;
		}long long cha=a[2]-a[1];
		long long shang=d/cha;
		if(shang<=1||shang*2-1>=n){
			cout<<0<<'\n';
			continue;
		}cout<<n-shang*2+1<<'\n';
	}
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	if(c<=6)solve300(t);
	if(11<=c&&c<=12)solveA(t);
}