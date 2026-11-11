#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[555555],k,a[555555],t[555555],st,ed,mi[1666666];
vector<int>g[1666666],g2[1666666];
void dfs(int nw,int ju,int la){
	if(ju>mi[ed+1000000])return;
	if(mi[nw]>ju)mi[nw]=ju;
	else return;
	for(int i=0;i<g[nw].size();i++){
		if((g[nw][i]<=1000000||g[nw][i]==1000000+ed)&&g[nw][i]!=la)dfs(g[nw][i],ju+g2[nw][i],nw);
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
		g[i+1000000].push_back(i);
		g[i].push_back(i+1000000);
		g2[i+1000000].push_back(w[i]);
		g2[i].push_back(w[i]);
	}int cnt=1;
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			scanf("%lld%lld",&a[j],&t[j]);
			if(j>1)g[cnt+499999].push_back(cnt+500000),g2[cnt+499999].push_back(0),g[cnt+500000].push_back(cnt+499999),g2[cnt+500000].push_back(0);
			g[cnt+500000].push_back(a[j]);
			g[a[j]].push_back(cnt+500000);
			g2[cnt+500000].push_back(t[j]);
			g2[a[j]].push_back(t[j]);
			cnt++;
		}
	}
	for(int i=1;i<=q;i++){
		for(int j=1;j<=m;j++)mi[j]=mi[j+1000000]=2e18;
		for(int j=1;j<=cnt;j++)mi[j+500000]=2e18;
		scanf("%lld%lld",&st,&ed);
		dfs(st+1000000,0ll,0);
		cout<<mi[ed+1000000]<<'\n';
	}
}

