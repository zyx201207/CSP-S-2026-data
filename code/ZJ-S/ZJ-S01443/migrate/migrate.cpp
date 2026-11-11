#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=5e3+6;
int n,c,t,x[maxn],d,dis[maxn],cnt[maxn];
vector<int>gr[maxn];
struct node{
	int v,w;
	bool operator < (node t) const{
		return w>t.w;
	};
};
priority_queue<node>q;
void dij(){
	while(!q.empty()){
		node now=q.top();
		q.pop();
		for(int i=0;i<gr[now.v].size();i++){
			int v=gr[now.v][i];
			if(dis[v]>dis[now.v]+1){
				cnt[v]=cnt[now.v];
				dis[v]=dis[now.v]+1;
				q.push({v,dis[v]});
			}
			else if(dis[v]==dis[now.v]+1){
				cnt[v]+=cnt[now.v];
			}
		}
	}
} 
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>c>>t;
    while(t--){
    	int ans=0;
    	cin>>n>>d;
    	for(int i=1;i<=n;i++){
    		cin>>x[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(abs(x[i]-x[j])<=d)gr[i].push_back(j);
			}
		}
		for(int i=1;i<=n;i++){
			memset(dis,0x3f3f3f3f,sizeof dis);
			dis[i]=0;
			cnt[i]=1;
			q.push({i,0});
			dij();
			for(int j=i+1;j<=n;j++){
				if(cnt[j]==2)ans++;
				cnt[j]=0;
			}
		}
		for(int i=1;i<=n;i++)gr[i].clear();
		cout<<ans<<"\n";
	}
    return 0;
}