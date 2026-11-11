#include <bits/stdc++.h>
using namespace std;
//long long
//printf
//scanf
int n,m;
long long ans=0;
long long a[200000];
void dfs(int x,int c,long long sum){
    if(c==m){
		ans=max(ans,sum);
	    return;	
	}	
	if(x==n+1){
	    return;	
	}
	for(int i=x;i<=n;i++){
		long long k=(sum&a[i]);
        dfs(i+1,c+1,k);
    }
    return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	for(int i=1;i<=n;i++){
		dfs(i+1,1,a[i]);
	}
	printf("%lld",ans);
	return 0;	
}
