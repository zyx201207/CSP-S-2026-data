#include<bits/stdc++.h>
using namespace std;
long long w[1100005];
struct o{
	int x;
	long long y;
};
vector<o>v2[505],ro[500005];
long long d[505][505];
bool pd[505][505];
void bfs(int X){
	priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>p;
	p.push({0,X});
	while(!p.empty()){
		pair<long long,int>R=p.top();
		p.pop();
		if(pd[X][R.second])continue;
		pd[X][R.second]=true;
		d[X][R.second]=R.first;
		// cout<<X<<" "<<R.second<<" "<<R.first<<"\n";
		for(o i:v2[R.second]){
			if(!pd[X][i.x]){
				p.push({i.y+R.first,i.x});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int C,n,m,de,q;
	// cin>>C>>n>>m>>de>>q;
	scanf("%d%d%d%d%d",&C,&n,&m,&de,&q);
	for(int i=1;i<=m;i++){
		scanf("%lld",&w[i]);
	}
	for(int i=1;i<=n;i++){
		int P;
		scanf("%d",&P);
		for(int j=1;j<=P;j++){
			int x,y;
			scanf("%d%d",&x,&y);
			ro[x].push_back({i,y});
		}
	}
	for(int i=1;i<=m;i++){
		for(o j:ro[i]){
			for(o k:ro[i]){
				// cout<<j.x<<" "<<k.x<<" "<<i<<"\n";
				if(j.x!=k.x)
					v2[j.x].push_back({k.x,j.y+k.y}),v2[k.x].push_back({j.x,j.y+k.y});
			}
		}
	}
	for(int i=1;i<=n;i++){
		bfs(i);
	}
	// cout<<w[1]<<" "<<w[2]<<" "<<w[3]<<" ";
	// for(int i=1;i<=n;i++){
	// 	for(int j=1;j<=n;j++)cout<<i<<" "<<j<<" "<<d[i][j]<<"\n";
	// }
	for(int i=1;i<=q;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		long long ans=100000000000000000;
		for(o j:ro[x]){
			for(o k:ro[y]){
				int XX=j.x,YY=k.x;
				long long yu=w[x]+w[y]+j.y+k.y+d[XX][YY];
				// if(yu==24)cout<<w[x]<<" "<<w[y]<<" "<<d[XX][YY]<<" "<<j.y<<" "<<k.y<<"\n";
				ans=min(ans,yu);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}