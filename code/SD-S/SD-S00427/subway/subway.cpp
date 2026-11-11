#include <bits/stdc++.h>
#define int long long
const int N=5e5+100;
using namespace std;
typedef pair<int,int> pii;
int w[N];
vector<pii> ht[N];
vector< pair<pair<int,int>,int> > a[N];
int dis[N];
queue<pii> q;
int dij(int d,int okp){
	while(!q.empty())q.pop();
	q.push({d,0});
	while(!q.empty()){
		pii p=q.front();
		q.pop();
		for(auto i:a[p.first]){
			if(p.second==0||p.second==i.first.second){
			//	cout<<dis[i.first.first]<<" "<<i.first.first<<'\n';
				if(dis[i.first.first]>dis[p.first]+i.second){
					dis[i.first.first]=dis[p.first]+i.second;
					q.push({i.first.first,i.first.second});
			//		cout<<dis[i.first.first]<<" "<<i.first.first<<" "<<dis[p.first]<<" "<<p.first<<" "<<i.second<<"\n";
				}
				
			}
			else if(p.second!=0&&p.second!=i.first.second){
			//	cout<<dis[i.first.first]<<" "<<i.first.first<<'\n';
				if(i.first.second!=p.second&&dis[i.first.first]>dis[p.first]+i.second){
					dis[i.first.first]=dis[p.first]+i.second;
					q.push({i.first.first,i.first.second});
			//		cout<<dis[i.first.first]<<" "<<i.first.first<<" "<<dis[p.first]<<" "<<p.first<<" "<<i.second<<" "<<p.second<<"\n";
				}
			}
		}
	}	
	return dis[okp];
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		scanf("%lld",w+i);
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		int x,y;
		cin>>x>>y;
		ht[x].push_back({i,y});
		for(int i=1;i<k;i++){
			int j,t;
			scanf("%lld%lld",&j,&t);
			a[x].push_back({{j,i},y});
			ht[j].push_back({i,t});
			x=j,y=t;
		}	
	}
	for(int i=1;i<=q;i++){
			int x,y;
			scanf("%lld%lld",&x,&y);
			for(int i=1;i<=m;i++){
				dis[i]=1e18;
			}
			dis[x]=0;
			cout<<dij(x,y)+w[x]+w[y]<<"\n";
		}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/

