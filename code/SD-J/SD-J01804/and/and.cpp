#include<bits/stdc++.h>
using namespace std;
long long n,m,book[200],A[200100],B[200100],C[200100],t,j,i,u,ans;
int chek(long long x,long long j){
	return (x>>j)&1;
}
int chag(long long x,long long i){
	x=x|(1<<i);
	return x;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=n;i++){
		scanf("%lld",&A[i]);
		C[i]=i;
		B[i]=i;
	}
	t=n;
	for(i=29;i>=0;i--){
		u=0;
		for(j=1;j<=t;j++){
			if(chek(A[C[j]],i)){
				u++;
				B[u]=C[j];
			}
		}
		if(u>=m){
			for(j=1;j<=u;j++){
				C[j]=B[j];
				t=u;
			}
			ans=chag(ans,i);
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
}
