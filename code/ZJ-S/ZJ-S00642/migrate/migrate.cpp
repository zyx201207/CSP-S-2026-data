#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> pii;
const int N=1e6+5,INF=LLONG_MAX;
int c,t,n,d,x[N],cnt[N],minn[N];
void bfs(int s){
	queue<pii> q;
	q.push({s,0});
	while(!q.empty()){
		int cur=q.front();q.pop();
		if(cnt[cur.first]==0) minn[cur.first]=cur.second;
		if(cur.second==minn) cnt[cur.first]++;
		for(int i=cur.first+1;i<=n;i++){
			if(x[i]-x[cur.first]<=d) q.push({i,cur.second+1});
			else break;
		}
	}
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>c>>t;
    while(t--){
    	memset(a,0,sizeof(a));
    	cin>>n>>d;
    	int ans=0;
    	for(int i=1;i<=n;i++) cin>>x[i];
    	for(int i=1;i<=n-2;i++){
    		fill(cnt,cnt+n+1,0);
    		bfs(i);
    		for(int j=i+2;j<=n;j++){
    			if(cnt[j]==2) ans++;
			}
		}
		cout<<ans/2;
	}
    return 0;
}