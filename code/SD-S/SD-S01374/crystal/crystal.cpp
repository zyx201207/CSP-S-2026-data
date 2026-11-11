#include<bits/stdc++.h>
using namespace std;
long long n,m,A[500100],i,j,l,r,ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=n;i++){
		scanf("%lld",&A[i]);
	}
	sort(A+1,A+n+1);
	l=1;
	r=0;
	for(i=1;i<=n;i++){
		r=r+A[i];
		if((m+r)/(i-l+1)<A[i]){
			r-=A[l];
			l++;
		}
		ans=max(ans,i-l+1);
	}
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
