#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
long long A[500500],B[500500];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,i,l,cnt = 0,ans = 0;
	scanf("%lld%lld",&n,&m);
	for(i = 1;i <= n;i++){
		scanf("%lld",&A[i]);
	}
	sort(A+1,A+1+n);
	l = 1;
	for(i = 2;i <= n;i++){
		cnt += (A[i] - A[i-1])*(i-l);
		while(cnt > m){
			l++;
			cnt -= A[i] - A[l-1];
		}
		ans = max(ans,i-l+1);
	}
	printf("%lld",ans);
}
//8min.it's too easy!!! 
