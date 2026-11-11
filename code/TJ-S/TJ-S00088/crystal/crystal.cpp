#include<bits/stdc++.h>
#define LANH using
#define AK namespace
#define CSPS std
LANH AK CSPS;
typedef long long ll;
int n;
ll m,a[500009];
ll dp[500009];
int maxn;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m); 
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)dp[i]=dp[i-1]+a[i];
	for(int i=1,j=1;i<=n;i++){
		while(j<i&&a[i]*(i-j+1)-(dp[i]-dp[j-1])>m){
			j++;
		}
		maxn=max(maxn,i-j+1);
	}
	printf("%d",maxn);
	return 0;
}
