#include<bits/stdc++.h>
using namespace std;
long long n,m,a[220000],k=(1<<30)-1;
bool f[220000];
bool qw(long long a,long long b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		f[i]=1;
	} 
//	sort(a+1,a+n+1,qw);
//	printf("\n");
//	for(int i=1;i<=n;i++){
//		printf("%d ",a[i]);
//	} 
	for(int j=29;j>=0;j--){
		long long p=(1<<j),ml=0;
		for(int i=1;i<=n;i++){
			if((p&a[i])&&f[i]){
				ml++;
			}
		}
		if(ml<m){
			continue;
		}
		for(int i=1;i<=n;i++){
			if(!f[i]){
				continue;
			}
			if(p&a[i]){
				f[i]=1;
			}
			else{
				f[i]=0;
			}
		}
	} 
	long long lp=0;
	for(int i=1;i<=n;i++){
		if(f[i]){
			lp++;
			k&=a[i];
			if(lp==m){
				break;
			}
		}
	}
	printf("%lld",k);
	return 0;
}
