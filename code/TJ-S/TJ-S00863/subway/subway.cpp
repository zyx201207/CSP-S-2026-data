#include<bits/stdc++.h>
using namespace std;
long long c,n,m,o[700000],d,xia[700000],q,w[500000],s[50000],tr[10000][10000],t[50000],a[50000];
vector<long long>di[50000],xi[50000];
void dfs(long long x,long long y){
	if(x==y){
		o[y]=o[x];
		return;
	}
		for(int i=0;i<xi[x].size();i++){
		if(o[x]+w[x]+tr[x][i]<o[xia[xi[x][i]]]){
			o[xia[xi[x][i]]]=o[x]+w[x]+tr[x][i];
			dfs(xia[xi[x][i]],y);
		}
	}
	for(int i=0;i<di[x].size();i++){
		if(o[x]<o[di[x][i]]){
			o[di[x][i]]=o[x];
			dfs(di[x][i],y);
		}
	}
}
int main(){
//freopen("subway","r",stdin);
////	freopen("subway","r",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	
	for(int i=1;i<=m;i++){
		scanf("%lld*",&w[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%lld",&s[i]);
		for(int j=1;j<=s[i];j++){
			scanf("%lld%lld",&a[j],&t[j]);
			tr[j][i]=t[j];
			xi[a[j]].push_back(i);
		}
		xia[i]=a[1];
		for(int o=1;o<=s[i];o++){
			for(int j=1;j<=s[i];j++){
				if(o!=j){
					di[a[o]].push_back(a[j]);
				}
			}
		}
	}
	for(int i=1;i<=q;i++){
		long long x,y;
		for(int i=1;i<=m;i++){
			o[i]=20000000;
		}
		scanf("%lld%lld",&x,&y);
	
		o[x]=0;
		dfs(x,y);
		printf("%lld\n",o[y]);
	}
	return 0;
}
