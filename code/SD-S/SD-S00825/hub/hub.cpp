#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define PII pair<int,int>
#define PLL pair<ll,ll>
#define PQ priority_queue
#define ump unordered_map
#define inf 0x3f3f3f3f
#define mod 998244353
using namespace std;
const int N=2e6+10;
int p[N];
int find(int x){
	if(x!=p[x]) return p[x]=find(p[x]);
	return p[x];
}
void merge(int a,int b){
	a=find(a),b=find(b);
	if(a!=b){
		p[a]=b;
	}
}
void solve(){
	int n,k;
	scanf("%d %d",&n,&k);
	vector<vector<int>> g(n+1);
	if(k==n){
		printf("0\n");
		return;
	}
	if(n<=20){
		vector<vector<int>> m(n+1,vector<int>(n+1,0));
		for(int i=1;i<n;i++){
			int u,v;
			scanf("%d %d",&u,&v);
			m[u][v]=m[v][u]=1;
		}
		int ans=inf;
		for(int s=0;s<(1<<n);s++){
			for(int i=1;i<=n;i++) p[i]=i;
			int cnt=0;
			vector<int> h,vis(n+1,0);
			for(int i=0;i<n;i++){
				if(s&(1<<i)){
					h.push_back(i+1);
				}
			}
			if(h.size()!=k) continue;
			for(int i=0;i<h.size();i++){
				if(vis[h[i]]) continue;
				vis[h[i]]=inf;
				cnt++;
				for(int j=0;j<h.size();j++){
					if(m[h[i]][h[j]]) vis[h[j]]=inf;
				}
			}
			if(cnt>2) continue;
			int now=0;
			for(int i=1;i<=n;i++){
				if(!vis[i]){
					int res=0,flag=0;
					queue<int> q;
					q.push(i);
					vector<int> st(n+1,0);
					while(q.size()){
						int u=q.front();q.pop();
						if(st[u]) continue;
						st[u]=1;
						res++;
						for(int j=1;j<=n;j++){
							if(!m[u][j]) continue;
							
							if(vis[j]!=inf){
								if(!st[j]) q.push(j);
							}
							else{
								flag=1;
								
								now=max(now,res);
								break;
							}
						}
						if(flag) break;
					}
				}
			}
			ans=min(ans,now);
		}
		printf("%d\n",ans);
		return;
	}
	for(int i=1;i<n;i++){
		int u,v;
		scanf("%d %d",&u,&v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	int m=(n-1)/2;
	printf("%d\n",max(0,(m+1-k)/4+((m+1-k)%4==0?0:1)));
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout); 
	int c,t;
	scanf("%d %d",&c,&t);
	while(t--){
		solve();
	}
	
	
	return 0;
} 
