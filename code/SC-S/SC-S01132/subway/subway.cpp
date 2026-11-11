#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> par;
const int man=5e5+10;
const ll inf=0x3f3f3f3f3f3f3f3f;
ll n,m,dis[man],pnt[man];
bool vis[man];
vector<ll>pas[man];
vector<par>sub[man];
ll fake_bound(ll idx,ll sta){
	ll l=0,r=sub[idx].size()-1,ans=-1,mid;
	while(l<=r){
		mid=(l+r)>>1;
		if(sub[idx][mid].first>=sta){
			ans=mid;
			r=mid-1;
		}else{
			l=mid+1;
		}
	}
	return ans;
}
void dij(int s){
	memset(dis,0x3f,sizeof dis);
	memset(vis,0,sizeof vis);
	priority_queue<par,vector<par>,greater<par>>q;
	dis[s]=0;
	q.push({0,s});
	while(!q.empty()){
		int u=q.top().second;
		q.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(int i=0;i<pas[u].size();i++){
			int num=pas[u][i],pos=fake_bound(num,u);
			for(int i=0;i<sub[num].size();i++){
				if(i==pos)continue;
				if(!vis[sub[num][i].first]&&dis[sub[num][i].first]>dis[u]+sub[num][pos].second+sub[num][i].second){
					dis[sub[num][i].first]=dis[u]+sub[num][pos].second+sub[num][i].second;
					q.push({dis[sub[num][i].first],sub[num][i].first});
				}
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>pnt[i];
	}
	for(int i=1;i<=n;i++){
		ll k;
		cin>>k;
		for(int j=1;j<=k;j++){
			ll a,t;
			cin>>a>>t;
			sub[i].push_back({a,t});
			pas[a].push_back(i);
		}
		sort(sub[i].begin(),sub[i].end());
	}
	while(q--){
		int s,t;
		cin>>s>>t;
		dij(s);
		cout<<pnt[s]+pnt[t]+dis[t]<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}