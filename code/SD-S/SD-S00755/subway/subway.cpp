#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,k,dd,qk;
struct ed{
	int to,dis;
};
vector<ed> e[510005];
int d[500105];
int w[510005];
bool v[510005];
int a,t;
struct ques{
	int id,x,y;
}que[100005];
bool cmp(ques x,ques y){
	return x.x<y.x;
}
int ans[100005];
priority_queue<pair<int,int> > q;
void dijkstra(int s){
	memset(d,0x3f,sizeof(d));
	while(!q.empty())q.pop();
	q.push(make_pair(0,s));
	memset(v,0,sizeof(v));
	v[s]=1;
	d[s]=0;
	while(!q.empty()){
		signed x=q.top().second;
		q.pop();
		v[x]=1;
		for(int i=0;i<e[x].size();i++){
			int p=e[x][i].to;
			if(v[p])continue;
			d[p]=min(d[p],d[x]+e[x][i].dis);
			q.push(make_pair(-d[p],p));
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>m>>n>>dd>>qk;
	for(int i=1;i<=n;i++){
		cin>>w[i];
	}
	for(int i=1;i<=m;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a>>t;
			ed t1={a,t};
			ed t2={n+i,t};
			e[n+i].push_back(t1);
			e[a].push_back(t2);
		}
	}
	for(int i=1;i<=qk;i++){
		int x,y;
		cin>>x>>y;
		que[i].id=i;
		que[i].x=x;
		que[i].y=y;
		//cout<<d[x][y]+w[x]+w[y]<<endl;
	}
	sort(que+1,que+qk+1,cmp);
	for(int i=1;i<=qk;i++){
		//cout<<que[i].x<<endl;
		if(que[i].x!=que[i-1].x)dijkstra(que[i].x);
		ans[que[i].id]=d[que[i].y]+w[que[i].x]+w[que[i].y];
	}
	for(int i=1;i<=qk;i++){
		cout<<ans[i]<<endl; 
	}
	return 0;
}
/*0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/ 
/*0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/

