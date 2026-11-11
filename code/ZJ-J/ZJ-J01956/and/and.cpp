#include<bits/stdc++.h>
using namespace std;
const long long MA=2e5+100;
long long n,m;
long long x[MA],f[MA];
long long ans=0;
void dfs(long long k,long long val){
	if(k>m){
		ans=max(ans,val);
		return ;
	}
	for(long long i=1;i<=n;i++){
		if(f[i]==0){
			f[i]=1;
			dfs(k+1,val&x[i]);
			f[i]=0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	long long pdA=1;
	for(long long i=1;i<=n;i++){
		scanf("%lld",&x[i]);
		if(pdA==1){
			long long ceA=x[i]+1;
			long long sum=1;
			while(1){
				if(sum==ceA){
					break;
				}
				if(sum>ceA){
					pdA=0;
					break;
				}
				sum*=2;
			}
		}
	}
	if(pdA==1){
		sort(x+1,x+1+n);
		printf("%lld",x[n-m+1]);
	}
	else{
		dfs(1,pow(2,30)-1);
		printf("%lld",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
