#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int a[N],s[N];
vector<int>e,v[3*N],k,q;
//stack<int>st;
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n,m;
	bool vis=true;
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		e.push_back(a[i]);
		if(a[i]<a[i-1])vis=false;
	}
	if(vis==true) {
		for(int i=1; i<=n; i++) v[a[i]].push_back(i);
		for(int i=1; i<=n; i++)if(v[i].size()%2==1)s[i]=n;
		for(int i=1; i<=m; i++)cout<<s[i]<<' ';
		return 0;
	}
	for(int i=1; i<=n; i++) {
//		for(int i=1; i<=m; i++)v[i].clear();
		q.clear();
		int len=e.size();
//		cout<<len<<' ';
		for(int j=0; j<len; j++) {
			int lenk=k.size();
			for(int f=0; f<lenk; f++) {
				if(k[f]==e[j]) {
					for(int x=f; x<lenk; x++)q.push_back(k[x]);
					for(int x=f; x<lenk; x++)k.pop_back();
					break;
				}
			}
			k.push_back(e[j]);
//			if(e.size()==0)e.push_back(q[0]),q.pop_front();
//			cout<<k.size()<<' ';
		}
		int lenk=k.size();
//		cerr<<lenk<<'\n';
		for(int j=0; j<lenk; j++)s[k[j]]++;
//		cout<<lenk<<' ';
//		for(int j=0;j<lenk;j++)cout<<k[j]<<":"<<s[k[j]]<<' ';
//		cout<<'\n';
		e=q;
	}
	for(int i=1; i<=m; i++)cout<<s[i]<<' ';
	return 0;
}
