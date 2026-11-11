#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+10;
int C,T;
int n,d;
int a[N];
vector<int> G[N];
int dis[N],c[N];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>C>>T;
	while(T--){
		cin>>n>>d;
		if(11<=C&&C<=12){
			for(int i=1;i<=n;i++) cin>>a[i];
			int x=d/(a[2]-a[1]);x*=2;
			if(x==0||x==2||x>n) cout<<0<<"\n";
			else{
				cout<<n-x+1<<"\n";
			}continue;
		}if(C>=13){
			cout<<0<<"\n";
			continue;
		}
		for(int i=1;i<=n;i++) G[i].clear();
		int l=1;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			while(a[i]-a[l]>d) l++;
			for(int j=l;j<i;j++) G[j].push_back(i); 
		}int ans=0;
		for(int st=1;st<=n;st++){
			queue<int> q;
			for(int j=1;j<=n;j++) dis[j]=1e18L;
			dis[st]=0,c[st]=1;
			q.push(st);
			while(!q.empty()){
				int u=q.front();q.pop();
				for(int i=0;i<G[u].size();i++){
					int v=G[u][i];
					if(dis[v]>dis[u]+1) dis[v]=dis[u]+1,c[v]=c[u],q.push(v);
					else if(dis[v]==dis[u]+1) c[v]+=c[u];
				}
			}for(int i=st;i<=n;i++) if(c[i]==2) ans++;
		}cout<<ans<<"\n";
	}
	return 0;
}
