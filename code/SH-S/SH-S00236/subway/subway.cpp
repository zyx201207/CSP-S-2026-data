#include<bits/stdc++.h>
using namespace std;
vector<pair<int,pair<int,int>>> a;
vector<pair<int,vector<pair<int,int>>>> b;  
int dfs711(int x,int y,int z) {
	if(z==x) return y;
	return dfs711(a[x].second.first,y+a[x].second.second,z);
}

int dfs(int x,int y,int z) {
	if(z==x) return y;
	int s=INT_MAX;
	for(int i=0;i<b[x].second.size();++i) {
		s=min(s,dfs(b[x].second[i].first,y+b[x].second[i].second,z));
	}
	return s;
}
int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	if(7<=c&&c<=11) {
		a.resize(m);
		for(int i=0;i<m;++i) {
			int x;cin>>x;
			a[i].first=x;
		}
		for(int i=0;i<n;++i) {
			int x1;cin>>x1;//
			int y1,x2,y;cin>>x1>>y1>>x2>>y;
			a[x1].second.first=x2;
			a[x1].second.second=y1+y;
			a[x2].second.first=x1;
			a[x2].second.second=y1+y;
		}
		int x_x_xxx;cin>>x_x_xxx;
		for(int i=0;i<q;++i) {
			int x,y;
			cin>>x>>y;
			cout<<dfs711(x,a[x].first,y)+a[y].first;
		}
	}
	b.resize(m);
	for(int i=0;i<m;++i) {
		int x;cin>>x;
		b[i].first=x;
	}
	for(int i=0;i<n;++i) {
		int nn;cin>>nn;
		int x[nn],y[nn];
		for(int j=0;j<nn;++j) {
			cin>>x[j]>>y[j];
		}
		for(int j=0;j<nn;++j) {
			for(int k=0;k<nn;++k) {
				if(j==k) continue;
				b[x[j]].second.resize(1000010);
				b[x[j]].second[b[x[j]].second.size()].first=x[k];
				b[x[j]].second[b[x[j]].second.size()].second=y[k]+y[j];
			}
		}
	}
	int x_x_xxx;cin>>x_x_xxx;
	for(int i=0;i<q;++i) {
			int x,y;
			cin>>x>>y;
			cout<<dfs(x,b[x].first,y)+b[y].first;
		}
	return 0;
}
