#include <bits/stdc++.h>
using namespace std;
#define int long long
struct S{
	int id,w;
	bool operator < (const S&x) const{
		return w>x.w;
	}
};
struct Q{
	int a,b,id;
}q[100005];
bool cmp(Q a,Q b){
	return a.a<b.a;
}
int c,n,m,d,q1,w[500005],dd[500005],dis[1000005],ans[500005];
bool vis[1000005];
vector<int> a[505],t[505];
vector<S> arr[1000005];
void dijk(int a){
	for(int i=0;i<=m*(d+1);i++){
		dis[i]=1e17;
		vis[i]=0;
	}
	priority_queue<S> q;
	q.push({a,0});
	dis[a]=0;
	while(q.size()){
		int x=q.top().id;
		q.pop();
		if(vis[x]){
			continue;
		}
		vis[x]=1;
		int o=arr[x].size();
		for(int i=0;i<o;i++){
			int v=arr[x][i].id,w=arr[x][i].w;
			if(dis[v]>dis[x]+w){
				dis[v]=dis[x]+w;
				q.push({v,dis[v]});
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q1;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int c,b;
			cin>>b>>c;
			a[i].push_back(b);
			t[i].push_back(c);
		}
	}
	for(int i=1;i<=n;i++){
		int o=a[i].size();
		arr[a[i][0]+d*m].push_back({a[i][0]+dd[a[i][0]]*m,t[i][0]});
		arr[a[i][0]+dd[a[i][0]]*m].push_back({a[i][0]+d*m,t[i][0]});
		for(int j=1;j<o;j++){
			arr[a[i][j]+dd[a[i][j]]*m].push_back({a[i][j-1]+dd[a[i][j-1]]*m,0});
			arr[a[i][j-1]+dd[a[i][j-1]]*m].push_back({a[i][j]+dd[a[i][j]]*m,0});
			arr[a[i][j]+d*m].push_back({a[i][j]+dd[a[i][j]]*m,t[i][j]});
			arr[a[i][j]+dd[a[i][j]]*m].push_back({a[i][j]+d*m,t[i][j]});
		}
		for(int j=0;j<o;j++){
			dd[a[i][j]]++;
		}
	}
	for(int i=1;i<=q1;i++){
		cin>>q[i].a>>q[i].b;
		q[i].id=i;
	}
	sort(q+1,q+1+q1,cmp);
	for(int i=1;i<=q1;i++){
		if(q[i].a!=q[i-1].a){
			dijk(q[i].a+d*m);
		}
		ans[q[i].id]=dis[q[i].b+d*m]+w[q[i].a]+w[q[i].b];
	}
	for(int i=1;i<=q1;i++){
		cout<<ans[i]<<"\n";
	}
	return 0;
}
