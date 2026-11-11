#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,k,g,b,e;
int w[500055];
int a[500055];
int t[500055];
int o[500055];
bool f[500055];
int p[505];
vector<pair<int,int> >z[500055];
vector<int>h;
void dfs(int aa,int ss){
	if(aa==e){
		if(g==-1)g=ss;
		else g=min(g,ss);
		return;
	}
	for(int v=0;v<(int)z[aa].size();v++){
		for(int i=p[z[aa][v].first-1]+1;i<=p[z[aa][v].first];i++){
			if(f[a[i]])continue;
			f[a[i]]=true;
			h.push_back(a[i]);
			dfs(a[i],ss+z[aa][v].second+t[i]);
			h.pop_back();
			f[a[i]]=false;
		}
	}
	return;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		p[i]=p[i-1]+k;
		for(int v=1;v<=k;v++){
			cin>>a[p[i-1]+v]>>t[p[i-1]+v];
			z[a[p[i-1]+v]].push_back(make_pair(i,t[p[i-1]+v]));
		}
	}
	for(int i=1;i<=q;i++){
		cin>>b>>e;
			g=-1;
			f[b]=true;
			h.push_back(b);
			dfs(b,0);
			h.pop_back();
			g+=w[b]+w[e];
			f[b]=false;cout<<g<<endl;
	}
	return 0;
}
