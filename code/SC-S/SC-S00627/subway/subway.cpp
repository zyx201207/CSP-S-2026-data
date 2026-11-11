#include<bits/stdc++.h>
#define ll long long

using namespace std;
ll enter[500001];
int len[501],n,m;
ll ans;
bool pol[501][500001];
unordered_map<int,int> mp[501];
vector<int> lofp[500001],pofl[501]; //点的所有线，线的所有点
bool vis[501];
void dfs(int x, int y, int l, ll tim){
	vis[l]=1;
	if(pol[l][y]){
		ans=min(ans,tim+mp[l][y]);
	}
	for(auto np:pofl[l]){
		for(auto nl:lofp[np]){
			if(vis[nl]) continue;
			dfs(np,y,nl,tim+mp[l][np]+mp[nl][np]);
		}
	}
	return;
}
vector<pair<int,int>> e[1001];
ll d7[1001][1001];
bool vis7[1001];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int c,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>enter[i];
	}
	for(int i=1;i<=n;i++){
		int num,tim;
		cin>>len[i];
		int lie[3],litim=0;
		for(int j=1;j<=len[i];j++){
			cin>>num>>tim;
			pol[i][num]=1;
			mp[i][num]=tim;
			lofp[num].push_back(i);
			pofl[i].push_back(num);
			if(c>=7 && c<=11){
				lie[j]=num;
				litim+=tim;
			}
		}
		if(c>=7 && c<=11){
			e[lie[1]].push_back({litim,lie[2]});
			e[lie[2]].push_back({litim,lie[1]});
		}
	}
	int best_change_20;
	ll min_tim_20=1e18;
	if(c==20 || c==21){
		for(int i=1;i<=m;i++){
			if(!pol[1][i] || !pol[2][i]) continue;
			if(mp[1][i]+mp[2][i]<min_tim_20) min_tim_20=mp[1][i]+mp[2][i],best_change_20=i;
		}
	}
	if(c>=7 && c<=11){
		priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>> >q;
		for(int i=1;i<=m;i++) for(int j=1;j<=m;j++) d7[i][j]=1e18;
		for(int st=1;st<=m;st++){
			for(int ii=1;ii<=m;ii++) vis7[ii]=0;
			q.push({0,st});
			d7[st][st]=0;
			while(!q.empty()){
				int x=q.top().second;
				ll d=q.top().first;
				q.pop();
				if(vis7[x]) continue;
				vis7[x]=1;
				for(auto o:e[x]){
					int y=o.second;
					ll w=o.first;
					if(d+w<d7[st][y]) {
						d7[st][y]=d7[y][st]=d+w;
						q.push({d7[st][y],y});
					}
				}
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		ans=1e18;
		if(c==20 || c==21){
			if(pol[1][x] && pol[1][y]){
				ans=min(ans,enter[x]+enter[y]+mp[1][x]+mp[1][y]);
			} 
			if(pol[2][x] && pol[2][y]){
				ans=min(ans,enter[x]+enter[y]+mp[2][x]+mp[2][y]);
			} 
			if(!(pol[1][x] && pol[1][y]) && !(pol[2][x] && pol[2][y])){
				if(pol[1][x]){
					ans=min(ans,enter[x]+enter[y]+mp[1][x]+mp[2][y]+mp[1][best_change_20]+mp[2][best_change_20]);
				}else {
					ans=min(ans,enter[x]+enter[y]+mp[2][x]+mp[1][y]+mp[1][best_change_20]+mp[2][best_change_20]);
				}
			}
			cout<<ans<<'\n';
			continue;
		}
		if(c<=6){
			for(int i=1;i<=n;i++){
				for(int i=1;i<=n;i++) vis[i]=0;
				if(pol[i][x] && !vis[i]) dfs(x,y,i,enter[x]+enter[y]+mp[i][x]);
			}
			cout<<ans<<'\n';
		}
		if(c>=7 && c<=11){
			cout<<d7[x][y]+enter[x]+enter[y]<<'\n';
		}
	}
	
	return 0;
}