#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,m,n,d,q;
int nn;
int in[500005];
int w[500005];
vector<pair<int,int>>to[1000006];
int ans[100005];
vector<pair<int,int>>qu[500005];
int dis[1000006];
bool v[1000006];
void bfs(int s){
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
	for(int i=1;i<=nn;i++){
		dis[i]=0x3f3f3f3f3f3f3f3f;
		v[i]=0;
	}
	dis[s]=0;
	q.push({0,s});
	while(!q.empty()){
		int x=q.top().second;
		q.pop();
		if(v[x])continue;
		v[x]=1;
		for(pair<int,int>i:to[x]){
			int y=i.first,w=i.second;
			if(dis[x]+w<dis[y]){
				dis[y]=dis[x]+w;
				q.push({dis[y],y});
			} 
		} 
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>m>>n>>d>>q;
	nn=n;
	for(int i=1;i<=n;i++){
		cin>>w[i];
	}
	for(int i=1;i<=m;i++){
		int k;
		cin>>k;
		int oda=-1,odt;
		if(k>2)nn++;
		for(int i=1;i<=k;i++){
			int a,t;
			cin>>a>>t;
			if(k==1)continue;
			else if(k==2){
				if(i==1){
					oda=a;
					odt=t;
					continue;
				}
				else{
					to[oda].push_back({a,odt+t});
					to[a].push_back({oda,odt+t});
					continue;
				}
			}
			else{
				to[a].push_back({nn,t});
				to[nn].push_back({a,t});
			}
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		qu[x].push_back({y,i});
		ans[i]=w[x]+w[y];
	}
	for(int i=1;i<=n;i++){
		bfs(i);
		for(pair<int,int>j:qu[i]){
			ans[j.second]+=dis[j.first];
		}
	}
	for(int i=1;i<=q;i++){
		cout<<ans[i]<<"\n";
	}
	
	return 0; 
}
/*
n=500005,
图
00000000
--------  ki
\/\/\/\\ti
m
\/\/\/\\

N=1000006
M=10000007+500005!!!

缩起来
. i号线
/\\\\\\ ti
m
\/\\/\/\
N=500005+500(m+n) 
M=500005(ki)
做法配上 n^2lgn的djstl可得约44 
A:
N=m M=n 
 
 
*/
