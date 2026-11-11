#include<bits/stdc++.h>
#define int long long
using namespace std;
int w[500005];
vector<int>a[500005],t[500005],b[505];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		scanf("%lld",&w[i]);
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int kk,tt;
			scanf("%lld%lld",&kk,&tt);
			a[kk].push_back(i);
			t[kk].push_back(tt);
			b[i].push_back(kk);
		}
	}
	while(q--){
		int x,y;
		scanf("%lld%lld",&x,&y);
		int ans=0;
		ans+=w[x];
		ans+=w[y];
		priority_queue<pair<int,int>>q;
		vector<int>dist(500005,0x3f3f3f3f);
		vector<bool>vis(500005,0);
		q.push({0,x});
		dist[x]=0;
		while(q.size()){
			int r=q.top().second;
			q.pop();
			if(vis[r])continue;
			vis[r]=true;
			for(int i=0;i<a[r].size();i++){
				int rr=a[r][i],tt=t[r][i];
				for(int j:b[rr]){
					int wt;
					for(int o=0;o<a[j].size();o++){
						if(a[j][o]==rr){
							wt=t[j][o];
							break;
						}
					}
					if(dist[j]>dist[r]+tt+wt){
						dist[j]=dist[r]+tt+wt;
						q.push({-dist[j],j});
					}
				}
			}
		}
		ans+=dist[y];
		printf("%d\n",ans);
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

