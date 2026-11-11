#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],ans,sum;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(long long i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(long long i=0;i<n;i++){
		for(long long j=i+1;j<n;j++){
			sum=a[i]&a[j];
			ans=max(sum,ans);
		}
	}
	printf("%d",ans);
	return 0;
}