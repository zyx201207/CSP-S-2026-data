#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int x,y;
vector<int> l[505];
int t[505];
vector<int> e[505];
int dis[500005];
int vis[500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> c >> m >> n >> d >> q;
	for(int i=1;i<=m;i++){
		int k;
		cin >> k;
		for(int j=1;j<=k;j++){
			int x,y;
			cin >> x >> y;
			l[i].push_back(x);
			e[x].push_back(i);
			t[i]=y;
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin >> x >> y;
		cout << t[x]+t[y];
	}	
	return 0;
}

