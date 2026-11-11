#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m;
vector<int>v,t,l,p;
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	v.resize(n+1);
	t.resize(m+1);
	l.resize(m+1);
	for(int i=1; i<=n; i++) {
		cin>>v[i];
		l[v[i]]=i;
	}
	for(int I=1; I<=n; I++) {
		p.clear();
		for(int i=I; i<=n; i++) {
			i=l[v[i]];
			p.push_back(v[i]);
		}
		for(int i=0; i<p.size(); i++) {
			t[p[i]]++;
		}
	}
	for(int i=1; i<=m; i++) {
		cout<<t[i]<<' ';
	}
	return 0;
}