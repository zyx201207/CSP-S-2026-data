#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e6+5
int n,k;
struct edge{
	int nxt,to;
}E[MAXN];
int head[MAXN],cnt;
void add(int u,int v){
	E[++cnt].nxt=head[u];
	E[cnt].to=v;
	head[u]=cnt;
}
void solve(){
	cin >> n >> k;
	for(int i=1;i<=n-1;++i){
		int x,y;
		cin >> x >> y;
		add(x,y);
		add(y,x);
	}
	if(n==k) cout << 0 << endl;
	else if(k==1) cout << 2 << endl;
	else cout << 1 << endl;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	int c,t;
	cin >> c >> t;
	for(int i=1;i<=t;++i){
		solve();
	}
	
	return 0;
} 
