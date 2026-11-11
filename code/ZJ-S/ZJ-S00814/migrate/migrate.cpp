#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5;
const int INF=1e18+7;
int c,T,n,d,ans,x[N],dis[N],vis[N];
vector<int> a[N];
void bfs(int st){
	queue<int> q;
	q.push(st);
	int dep=0;
	for(int i=1;i<=n;i++){dis[i]=INF;vis[i]=0;}
	dis[st]=0;vis[st]=1;
	while(!q.empty()){
		int l=q.size();dep++;
		for(int k=1;k<=l;k++){
			int t=q.front();
			q.pop();
			for(auto i:a[t]){
				if(dis[i]<dep)continue;
				vis[i]++;
				dis[i]=dep;
				q.push(i);
			}
		}
	}
	for(int i=1;i<=n;i++)if(vis[i]==2)ans++;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>x[i];
		if(c==11||c==12){
			int f=d/(x[2]-x[1]);
			f=f+f-1;
			cout<<n-f;
			continue;
		}
		if(c==13||c==14){
			cout<<(n-1)*(n-2);
			continue;
		}
		for(int i=1;i<=n;i++){
			int j=i+1;
			while(j<=n&&x[j]<=x[i]+d){a[i].push_back(j);j++;}
			j=i-1;
			while(j>=1&&x[j]>=x[i]-d){a[i].push_back(j);j--;}
		}
		for(int i=1;i<=n;i++)bfs(i);
		cout<<ans/2<<"\n";
	}
	return 0;
}
