#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define endl '\n'
#define int long long
using namespace std;
const int N=2e6+5;
int a[N];
int n,d;
vector<int>G[N];
int dis[N],cnt[N];
bool vis[N];
int ans=0;
void bfs(int s){
    for(int i=1;i<=n;i++)dis[i]=0,vis[i]=0,cnt[i]=0;
    vis[s]=1;
    queue<int>q;
    q.push(s);
    cnt[s]=1;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int v:G[u]){
            if(vis[v]){
                if(dis[v]==dis[u]+1){
                	cnt[v]+=cnt[u];
				}
            }else{
                dis[v]=dis[u]+1;
                vis[v]=1;
                cnt[v]=cnt[u];
                q.push(v);
            }
        }
    }
    for(int i=s;i<=n;i++){
        if(cnt[i]==2)ans++;
    }
}
void solve(){
	cin>>n>>d;
	bool flag=1;
    for(int i=1;i<=n;i++){
        G[i]=vector<int>();
        cin>>a[i];
        if(i>2){
        	if(a[i]-a[i-1]!=a[i-1]-a[i-2])flag=0;
		}
    }
    if(flag){
    	ans=0;
    	int m=0;
    	for(int i=2;i<=n;i++){
    		if(a[i]-a[1]<=d)m=i;
    		else break;
		}
		if(m<3)cout<<0<<endl;
		else{
			ans=(n-2*m+1)+2;
			if(ans<0)cout<<0<<endl;
			else cout<<ans<<endl;
		}
    	return;
	}
    if(a[n]-a[1]<=d){
    	cout<<0<<endl;
    	return;
	}
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(a[j]-a[i]<=d){
                G[i].push_back(j);
            }
        }
    }
    ans=0;
    for(int i=1;i<=n;i++){
        bfs(i);
    }
    cout<<ans<<endl;
}
signed main(void){
	IOS;
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
    cin>>c>>t;
    while(t--){
        solve();
    }
	return 0;
}

