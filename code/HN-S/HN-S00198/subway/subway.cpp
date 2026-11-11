#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 510;
int c,n,m,d,q;
ll w[N];
int main() {
//	freopen(".in", "r" , stdin);
//	freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	vector< vector<int> > v(m+1);
	vector< vector<int> > ti(n+1);
	vector< vector<int> > xl(n+1);
	for(int i=1 ; i<=m ; i++) {
		cin>>w[i];
	}
	for(int _ = 1 ; _ <=n ; _++) {
		int k;
		cin>>k;
		for(int i = 1 ; i<= k ; i++) {
			int a , t;
			cin>>a>>t;
			xl[_].push_back(a);
			int xx = xl[_][i-1];
			cout<<"---\n";
			ti[_].push_back(t);
		}
		cout<<"+++\n";
	}
	cin>>q;
	while(q--) {
		
	}
	return 0;
}

