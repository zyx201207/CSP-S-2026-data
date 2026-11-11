#include<bits/stdc++.h>
using namespace std;
//#define int long long
vector<pair<long long,pair<long long,long long> > > v[1000010];
vector<long long> a[510];
vector<long long> t[510];
vector<long long> id[510];
int tot;
long long w[500010];
long long dis[1000010];
bool vis[1000010];
long long ans[100010];
vector<pair<pair<long long,long long> ,long long> > qq[5000010];
pair<int,int> p[500010];
priority_queue<pair<long long,int>,vector<pair<long long,int> > ,greater<pair<long long,int> > > q;
void dijk(int s){
	memset(vis,0,sizeof(vis));
	memset(dis,0x3f,sizeof(dis));
	/*dis[s]=0;
	q.push({0,s});*/
	for(int i=1;i<=a[s][0];i++){
		dis[id[s][i]]=0;
		q.push({0,id[s][i]});
	}
	//cout << endl;
	while(q.size()){
		int x=q.top().second;
		q.pop();
		if(vis[x])continue;
		vis[x]=1;
		for(auto to:v[x]){
			//if(to.second.second==s)continue;
			if(dis[to.first]>dis[x]+to.second.first){
				dis[to.first]=dis[x]+to.second.first;
				q.push({dis[to.first],to.first});
			}
		}
	}
	for(int i=1;i<=a[s][0];i++){
		int x=id[s][i];
		//cout << x << " : " << endl;
		for(auto Q:qq[x]){
			//cout << Q.second << " ";
			ans[Q.second]=min(ans[Q.second],dis[Q.first.second]+Q.first.first);
		}
		//cout << endl;
	}
}
int main(){
	//system("fc subway.out subway5.ans");
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,n,m,d,q;
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=m;i++){
		cin >> w[i];
	}
	tot=m;
	for(int i=1;i<=n;i++){
		int k;
		cin >> k;
		a[i].push_back(k);
		t[i].push_back(k);
		id[i].push_back(k); 
		int x;
		for(int j=1;j<=k;j++){
			cin >> x;
			a[i].push_back(x);
			id[i].push_back(++tot);
			if(j!=1){
				v[id[i][j-1]].push_back({id[i][j],{0,i}});
				v[id[i][j]].push_back({id[i][j-1],{0,i}});
			}
			cin >> x;
			t[i].push_back(x);
			v[id[i][j]].push_back({a[i][j],{t[i][j],-1}});
			v[a[i][j]].push_back({id[i][j],{t[i][j],-1}});
		}
	}
	memset(ans,0x3f,sizeof(ans));
	for(int i=1;i<=q;i++){
		int x,y;
		cin >> x >> y;
		for(auto to:v[x]){
			qq[to.first].push_back({{to.second.first,y},i});
		}
		p[i]={x,y};
	}
	dijk(1);
	//cout << dis[3] << endl;
	for(int i=1;i<=n;i++){
		//cout << i << endl;
		dijk(i);
	}
	//cout << "!!!" << endl;
	for(int i=1;i<=q;i++){
		cout << ans[i]+w[p[i].first]+w[p[i].second] << '\n';
	}
	return 0;
}
