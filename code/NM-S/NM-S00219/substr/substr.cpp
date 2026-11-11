//substr
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e3+5;
ll ccccccc;
ll n,m,d,p,w[5*N],x[5*N],y[5*N];
ll k[5*N],a[5000][5*N],t[5000][5*N],minn=INT_MAX;

void dfs(ll dq,ll jh,ll ti,ll yi){
	if(dq==yi){
		minn=min(ti,minn);
		return;
	}
	for(int i=1;i<=n;i++){
		if(a[i][dq]){
			for(int j=1;j<=k[i];j++){
				if(j==i) continue;
				if(i==jh){
					dfs(j,i,ti,yi);
				}else{
					int ls=t[i][dq]+t[jh][dq];
					dfs(j,i,ls,yi);
				}
			}
		}
	}
}

int main(){
	freopen("substr.in","r",stdin);
	freopen("substr.out","w",stdout);
	scanf("%lld",&ccccccc);
	scanf("%lld%lld%lld%lld",&n,&m,&d,&p);
	for(int i=1;i<=m;i++){
		scanf("%lld",&w[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%lld",&k[i]);
		for(int j=1;j<=2*k[i];j++){
			scanf("%lld%lld",&a[i][j],t[i][j]);
		} 
	}
	for(int i=1;i<=p;i++){
		scanf("%lld%lld",&x[i],&y[i]);
		minn=INT_MAX;
		dfs(x[i],0,0,y[i]);
		minn=minn+w[x[i]]+w[y[i]];
		printf("%lld",minn);
	}
	
	
	
	return 0;
} 
