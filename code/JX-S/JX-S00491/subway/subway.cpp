#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q,o,p,st,en;//n<=500,m<=5e5,d<=20,q<=1e5
int w[500010],k[510],v[500010];
vector <int> a[510];
vector <pair<int,int> >s[500010];/*
void dfs(int x,int y,int z){//where value previous train-number
	return;
}*/
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cerr.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		a[i].push_back(-1);//start at number 1!
		for(int j=1;j<=k[i];j++){
			cin>>o>>p;
			a[i].push_back(p);
			s[o].push_back(make_pair(i,j));
		}
	}
	while(q--){
		cin>>st>>en;/*
		for(int i=1;i<=m;i++){
			v[i]=(long long)9e18;
		}
		dfs(st,0,-1);*/
		cout<</*v[en]+*/w[st]+w[en]<<'\n';
	}
	return 0;
}
