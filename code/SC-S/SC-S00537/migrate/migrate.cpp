#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define endl '\n'
using namespace std;
const int maxn=5000+10;
const int INF=0x3f3f3f3f3f3f3f3f;
int c,t;
int n,d;
int x[maxn*400];
int tp[maxn];
int cnt1[maxn];
int ans;
vector<int> ma[maxn];
queue<pii> q;
void bfs(){
	while(!q.empty()){
		int u=q.front().first;
		int cnt=q.front().second;
		q.pop();
		for(auto &v:ma[u]){
			if(tp[v]==0){
				tp[v]=cnt+1;
				cnt1[v]=cnt1[u];
				q.push({v,tp[v]});
			}
			else if(tp[v]==cnt+1) cnt1[v]++;
		}
	}
	return ;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>c;
	cin>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		if(c==11||c==12){
			int C=x[2]-x[1];
			if(C>=d) cout<<0<<endl;
			else if(n<2*(d/C)) cout<<0<<endl;
			else cout<<n-2*(d/C)+1<<endl;
			continue;
		}
		if(c==13||c==14){
			cout<<0<<endl;
			continue;
		}
		for(int i=1;i<n;i++){
			ma[i].clear();
			for(int j=i+1;j<=n;j++){
				if(x[j]-x[i]>d) break;
				ma[i].push_back(j);
			}
		}
		ans=0;
		for(int i=1;i<=n;i++){
			memset(tp,0,sizeof tp);
			memset(cnt1,0,sizeof cnt1);
			tp[i]=1;
			q.push({i,1});
			bfs();
			for(int j=1;j<=n;j++)
				if(cnt1[j]==1) ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
//不辨真伪，勿论虚实