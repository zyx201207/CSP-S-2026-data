#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int ceshi,T;
int n,k;
vector<int> G[N];
struct node{
	int len,ed;
}a[N];
int cnt[N],ans;
bool vis[N];
int llen=0;
void work(int u){
	int v1=0,v2=0;
	for(int v:G[u]){
		if(vis[v]) continue;
		if(!v1) v1=v;
		else v2=v;
	}
	int l1=a[v1].len,l2=a[v2].len;
	if(l1&&l2){
		int d1=a[v1].ed,d2=a[v2].ed;
		a[d1].len=l1+l2+1,a[d2].len=l1+l2+1;
		a[d1].ed=d2,a[d2].ed=d1;
		llen=max(llen,l1+l2+1);
		return;
	}
	if(l1&&!l2){
		int d1=a[v1].ed;
		a[d1].len++;
		a[d1].ed=u;
		a[u].len=a[d1].len;
		a[u].ed=d1;
		llen=max(llen,l1+l2+1);
		return;
	}
	if(l1&&!l2){
		int d2=a[v1].ed;
		a[d2].len++;
		a[d2].ed=u;
		a[u].len=a[d2].len;
		a[u].ed=d2;
		llen=max(llen,l1+l2+1);
		return;
	}
	a[u].len=1;
	a[u].ed=u;
	llen=max(llen,l1+l2+1);
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>ceshi>>T;
	while(T--){
		cin>>n>>k;
		for(int i=1;i<=n;i++) G[i].clear(),cnt[i]=0,a[i].len=0,a[i].ed=i,vis[i]=0;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			G[u].push_back(v);
			G[v].push_back(u);
			cnt[u]++,cnt[v]++;
		}
		ans=0;
		queue<int> q1,q2;
		for(int i=1;i<=n;i++)
			if(cnt[i]==1) q1.push(i);
		int res=n;
		while(++ans<=n){
			while(!q1.empty()){
				int u=q1.front();
				q1.pop();
				vis[u]=1;
				cnt[u]=0;
				res--;
				for(int v:G[u]){
					if(vis[v]) continue;
					cnt[v]--;
					if(cnt[v]==2) work(v);
					if(cnt[v]==1) q2.push(v);
				}
			}
			if(llen>=ans*2+1){
				if(k+ans*2-1>=res) break;
			}else{
				if(k+llen-2>=res) break;
			}
			while(!q2.empty()) q1.push(q2.front()),q2.pop();
		}
		cout<<ans<<"\n";
	}
	return 0;
}