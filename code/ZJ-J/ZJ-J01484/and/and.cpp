#include<bits/stdc++.h>
using namespace std;
	const int INF=INT_MAX;
    long long n,m,ans,fz[INF],ff[INF],ok[INF];
	int maxn,a[INF],x;
    int dfs(int num,int gs){
    	if(gs==m){
    		maxn=max(maxn,num);
    		return maxn;
		}
		if(num==0){
			return 0;
		}
		for(int i=1;i<=n;i++){
			if(ok[i]==0){
				ok[i]=1;
				dfs(num&a[i],gs+1);
				ok[i]=0;
			}
		}
	}
int main(){

    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++){
    	scanf("%lld",&a[i]);
	}
	fz[1]=a[1];
	for(int i=2;i<=n;i++){
		fz[i]=fz[i-1]&a[i];
	}
	ff[1]=a[n];
	for(int i=2;i<=n;i++){
		ff[i]=ff[i-1]&a[n-i+1];
	}
	if(m==1){
		maxn=-1;
		for(int i=1;i<=n;i++){
			maxn=max(maxn,a[i]);
		}
		printf("%lld",maxn);
		return 0;
	}
	if(m==n){
		for(int i=1;i<=n;i++){
			ans=ans&a[i];
		}
		printf("%lld",ans);
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				x=a[i]&a[j];
				maxn=max(maxn,x);
			}
		}
		printf("%lld",maxn);
		return 0;
	}
	if(m==n-1){
	    maxn=max(fz[n-1],ff[n-1]);
		for(int i=2;i<=n-1;i++){
			x=fz[i-1]&ff[n-i];
			maxn=max(maxn,x);
		}
		printf("%lld",maxn);
		return 0;
	}
	dfs(1,0);
	printf("%lld",maxn);
	return 0;
}