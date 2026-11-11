#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500009];
long long b[500009];
long long sum[500009];
long long oo=1;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(a[i]<a[i-1]){
			oo=0;
		}
	}
	memset(sum,0,sizeof(sum));
	if(oo){
		for(int i=1;i<=n;i++){
			sum[a[i]]=i;
		}
		printf("%lld",sum[1]);
		for(int i=2;i<=m;i++){
			printf(" %lld",sum[i]);
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		memset(b,0,sizeof(b));
		for(int j=i;j<=n;j++){
			if(b[a[j]]){
				for(int k=b[a[j]];k<j;k++){
					b[a[k]]=0;
				}
			}
			b[a[j]]=j;
		}
		for(int j=1;j<=m;j++){
			if(b[j]){
				sum[j]++;
			}
		}
	}
	printf("%lld",sum[1]);
	for(int i=2;i<=m;i++){
		printf(" %lld",sum[i]);
	}
	return 0;
}
