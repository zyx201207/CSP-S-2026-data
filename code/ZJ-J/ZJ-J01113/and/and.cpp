#include <bits/stdc++.h>
using namespace std;
void fre(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
}
long long n,m,a[200010],d[200001][30],p,l,t=0,ans=((1LL*1)<<(1LL*32))-1;
vector <long long> g[31];
vector <long long> g1[31];
void dfs(int x){
	if(g[x].size()==m){
		for(int i=0;i<g[x].size();i++){
			ans&=a[g[x][i]];
		}
		cout<<ans;
		return ;
	}
	for(int i=0;i<g[x].size();i++){
		for(int j=0;j<=29;j++){
			if(d[g[x][i]][j]){
				g1[j].push_back(g[x][i]);
			}
		}
	}
	for(int i=0;i<=29;i++){
		swap(g[i],g1[i]);
		g1[i].clear();
	}
	for(int i=x-1;i>=0;i--){
		if(g[i].size()>=m){
			dfs(i);
			return ;
		}
	}
	for(int i=0;i<g[x].size();i++){
		ans&=a[g[x][i]];
	}
	cout<<ans;
	return ;
}
int main(){
	fre();
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		t=0;
		l=a[i];
		while(l>=1){
			p=l%2;
			d[i][t]=p;
			if(p){
				g[t].push_back(i);
			}
			t++;
			l/=2;
		}
	}
	for(int i=29;i>=0;i--){
		if(g[i].size()>=m){
			dfs(i);
			return 0;
		}
	}
	cout<<0;
}
