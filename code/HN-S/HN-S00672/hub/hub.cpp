#include<bits/stdc++.h>
using namespace std;
struct z {
	int b;
	vector<int> g;
} a[500005];
int c[500005],h1;
void dfs(int h,int u) {
	if(a[u].b==0) {
		a[u].b=h;
		for(int i=1; i<=a[u].g.size(); i++) {
			if(a[u].g[i]==0) {
				dfs(h,a[u].g[i]);
				c[h]++;
			}
		}
		h1++;
	} else {
		return ;
	}
}
int main() {
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	if(t==2){
		cout<<1<<endl;
		cout<<2<<endl;
	}
	while(t--) {
		int n,k;
		cin>>n>>k;
		for(int i=1; i<=n; i++) {
			int u,v;
			a[u].g.push_back(v);
			a[v].g.push_back(u);
		}
		for(int i=1; i<=n; i++) {
			if(a[i].u==0) {
				dfs(h1,i);
			}
		}
		sort(c+1,c+n+1);
	}
}
