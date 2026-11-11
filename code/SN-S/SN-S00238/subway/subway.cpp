#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,p,a[5001],k[5001],v[5001][5001],t[5001][5001],o[5001];
struct node{
	int xx;
	int cnt;
};
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d",&c);
	while(c--){
		vector<int> g[500001];
		scanf("%d%d%d%d",&n,&m,&d,&p);
		for(int i=1;i<=m;i++){
			scanf("%d",&a[i]);
		}
		for(int i=1;i<=n;i++){
			scanf("%d",&k[i]);
			for(int j=1;j<=k[i];j++){
				scanf("%d",&v[i][j],&t[i][j]);
				o[v[i][j]]=t[i][j];
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=2;j<k[i];j++){
				g[j].push_back(v[i][j-1]);
				g[j].push_back(v[i][j+1]);
			}
		}
		while(p--){
			int x,y,ans=INT_MAX;
			scanf("%d%d",&x,&y);
			queue<node> q;
			q.push({x,a[x]+o[x]});
			while(!q.empty()){
				node f=q.front();
				q.pop();
				if(f.xx==y){
					ans=min(ans,f.cnt);
					continue;
				}
				for(int i=0;i<=g[f.xx].size()-1;i++){
					q.push({g[f.xx][i],f.cnt+a[g[f.xx][i]]+o[g[f.xx][i]]});
				}
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}
