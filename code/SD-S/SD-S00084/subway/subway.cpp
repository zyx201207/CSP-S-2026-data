#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define lowbit(x) x&(-x)
#define fst ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

const int N=5e5+10;//×¢ÒâÐÞ¸Ä

int c,n,m,d,q,ti;
vector<pii> ve[N];
int w[N];
int k[N];
vector<int> t[N],a[N];
struct node{
	int p,d;
	bool operator < (const node &b) const{
		return d>b.d;
	}
};
int vis[N],dis[2005][2005];
void dij(int s){
	memset(vis,0,sizeof vis);
	dis[s][s]=0;
	priority_queue<node> q;
	q.push({s,0});
	while(!q.empty()){
		int u=q.top().p;
		q.pop();
		if(vis[u]) continue;
		for(auto v:ve[u]){
			if(dis[s][v.fi]>dis[s][u]+v.se){
				dis[s][v.fi]=dis[s][u]+v.se;
				q.push({v.fi,dis[s][v.fi]});
			}
		}
	} 
}
void solve1(){
	memset(dis,0x3f,sizeof dis);

//	cout<<"rp++";
	for(int i=1;i<=n;i++){
		for(int j=1;j<k[i];j++){
		//	cout<<a[i][j-1]<<"->"<<a[i][j]<<' '<<t[i][1]<<' '<<t[i][0]<<endl;
			ve[a[i][j-1]].push_back({a[i][j],t[i][1]+t[i][0]});
			ve[a[i][j]].push_back({a[i][j-1],t[i][1]+t[i][0]});
		}
	}
	//dij(2);
//	for(int i=1;i<=m;i++) cout<<dis[i]<<' ';
	//cout<<endl;
	//for(int i=1;i<=m;i++) dij(i);
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<dis[x][y]+w[x]+w[y]<<endl;
	}
}

void solve2(){
	memset(dis,0x3f,sizeof dis);
	for(int i=1;i<=n;i++){
		for(int j=0;j<k[i]-1;j++){
			for(int z=j+1;z<k[i];z++){
				ve[a[i][j]].push_back({a[i][z],t[i][j]+t[i][z]});
				ve[a[i][z]].push_back({a[i][j],t[i][j]+t[i][z]});
			}
		}
	}
	for(int i=1;i<=m;i++) dij(i);
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<dis[x][y]+w[x]+w[y]<<endl;
	}
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	fst
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int x,y; cin>>x>>y;
			a[i].push_back(x);
			t[i].push_back(y);
		}
	}
	
	if((c>=7&&c<=11)) solve1();
	else solve2();
	return 0;
}
/*
0 7 5 10 2
1 2 3 4 5
2 1 1 2 2 
2 2 1 3 3 
2 3 1 4 4 
2 4 1 5 5
2 5 1 1 1
2 5 1 2 2
2 5 1 3 3
2 5
1 4

0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2



*/


