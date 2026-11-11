#include <bits/stdc++.h>
using namespace std;


#define i64 long long
#define MAXN 500005
int c,n,m,d,q;
i64 f[505][505],val[MAXN];
vector<pair<i64,i64> > g[MAXN];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >>c>>n>>m>>d>>q;
	for (int i = 1;i <= m;i ++) cin >>val[i];
	for (int i = 1,len;i <= n;i ++){
		cin >>len;
		int a;
		i64 t;
		for (int j = 1;j <= len;j ++){
			cin >>a>>t;
			g[a].emplace_back(i,t);	
		}
	}
	for (int i = 1;i <= n;i ++) for (int j = 1;j <= n;j ++) f[i][j]=1e17;
	for (int i = 1;i <= n;i ++) f[i][i]=0;
	for (int i = 1;i <= m;i ++){
		for (auto x:g[i]){
			int a1=x.first;
			i64 t1=x.second;
			for (auto y:g[i]){
				int a2=y.first;
				i64 t2=y.second;	
				if (a1==a2) continue;
				f[a1][a2]=min(f[a1][a2],t1+t2);
				f[a2][a1]=min(f[a2][a1],t1+t2);
			}
		}	
	}
	for (int k = 1;k <= n;k ++){
		for (int i = 1;i <= n;i ++){
			for (int j = 1;j <= n;j ++){
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);	
			}
		}
	}
	while (q--){
		int s,t;
		cin >>s>>t;
		i64 ans=val[s]+val[t];
		i64 add=1e17;
		for (auto x:g[s]){
			int a1=x.first;
			i64 t1=x.second;
			for (auto y:g[t]){
				int a2=y.first;
				i64 t2=y.second;	
				add=min(add,t1+t2+f[a1][a2]);
			}
		}
		cout <<ans+add<<'\n';
	}
	return 0;	
}
