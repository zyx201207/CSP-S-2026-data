#include<bits/stdc++.h>
using namespace std;
const long long M = 1e18;
const int N = 5e5 + 5;
struct edge{
	int to,nxt;
	long long vis;
}e[N];
int c,n,m,d,q,k,a[N],h[N],cnt,x,y;
long long w[N],t[N],ans,s[N];
void add(int u,int v,long long s){
	e[++cnt] = (edge){v,h[u],s};
	h[u] = cnt;
}
void dfs(int u,int v,long long sum){
	if(u == v){
		ans = min(ans,sum);
		return;
	}
	if(sum < s[u]){
		s[u] = sum;
	}else{
		return;
	}
	for(int i = h[u];i > 0;i = e[i].nxt){
		dfs(e[i].to,v,sum + e[i].vis);
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++){
		cin >> w[i];
	}
	for(int i = 1;i <= n;i++){
		cin >> k;
		for(int j = 1;j <= k;j++){
			cin >> a[j] >> t[j];
		}
		for(int l = 1;l < k;l++){
			for(int r = 2;r <= k;r++){
				add(a[l],a[r],t[l] + t[r]);
				add(a[r],a[l],t[l] + t[r]);
			}
		}
	}
	while(q--){
		ans = M;
		for(int i = 1;i <= m;i++){
			s[i] = M;
		}
		cin >> x >> y;
		dfs(x,y,0);
		cout << ans + w[x] + w[y] << '\n';
	}
	return 0;
} 
