#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500010]={},ans[300010]={};
vector<int>g;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++){
		g.clear();
		for(int j=i;j<=n;j++){
			int tmp=-1;
			for(int k=0;k<g.size();k++) if(g[k]==a[j]){tmp=k;break;}
			if(tmp!=-1){
				while(g[g.size()-1]!=g[tmp]) g.pop_back();
				g.pop_back();
			}
			g.push_back(a[j]);
		}
		for(int j=0;j<g.size();j++) ans[g[j]]++;
	}
	for(int i=1;i<=m;i++) printf("%lld ",ans[i]);
	return 0;
}
