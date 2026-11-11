#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int c,n,m,d,q,w1[500005],ans[500005],dis[505];
vector<vector<pair<int,int>>>a(n+1);
vector<int>myline[500005];
bool b[505];
int ft(int i,int j){
	for(auto k:a[i]){
		if(k.first==j)return k.second;
	}
}
int dij(int x,int y){
	memset(dis,0x3f,sizeof(dis));
	memset(b,0,sizeof(b));
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
	for(auto k:myline[x]){
		dis[k]=0;
		b[k]=0;
		q.push({0,k});
	}
	while(q.empty()){
		auto t=q.top();q.pop();
		if(b[t.second])continue;
		b[t.second]=1;
		for(auto j:a[t.first]){
			for(auto i:myline[j.first]){
				int ftt=ft(i,j.first);
				if(dis[i]>dis[t.first]+ftt+w1[j.first]){
					dis[i]=dis[t.first]+ftt+w1[j.first];
					q.push({dis[i],i});
				}
			}
		}
	}
	int res=0x3f3f3f3f;
	for(auto k:myline[y]){
		res=min(res,dis[k]);
	}
	return res;
}
signed main(){
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w1[i];
	}
	for(int i=1;i<=n;i++){
		int t1;
		cin>>t1;
		while(t1--){
			int s,w2;
			cin>>s>>w2;
			a[i].push_back({s,w2});
			myline[s].push_back(i);
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		ans[i]=dij(x,y);
	}
	for(int i=1;i<=q;i++){
		cout<<ans[i]<<endl;
	}
	return 0;
}