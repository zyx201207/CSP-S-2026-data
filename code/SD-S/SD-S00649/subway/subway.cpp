#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[500010],ki,a[500010],b[500010],xr,yr,ans=0;
long long bj[500010];
vector<pair<long long,long long>> t[500010];
void dfs(long long s,long long jg){
	if(s==yr){
		ans=min(ans,jg);
		return;
	}else if(jg>ans){
		return;
	}
	for(int i=0;i<t[s].size();i++){
		if(bj[t[s][i].first]==0){
			bj[t[s][i].first]=1;
			dfs(t[s][i].first,jg+t[s][i].second);
			bj[t[s][i].first]=0;
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%lld",&w[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%lld",&ki);
		for(int j=1;j<=ki;j++){
			scanf("%lld%lld",&a[j],&b[j]);
		}
		for(int j=1;j<=ki;j++){
			for(int k=j+1;k<=ki;k++){
				t[a[j]].push_back({a[k],b[j]+b[k]});
				t[a[k]].push_back({a[j],b[j]+b[k]});
			}
		}
	}
	
	for(int i=1;i<=q;i++){
		for(int p=1;p<=m;p++){
			bj[p]=0;
		}scanf("%lld%lld",&xr,&yr);
		ans=9e18;
		dfs(xr,0);
		printf("%lld\n",ans+w[xr]+w[yr]);
	}
	return 0;
} 
