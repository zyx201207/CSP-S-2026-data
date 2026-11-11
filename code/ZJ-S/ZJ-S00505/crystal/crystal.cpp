#include<bits/stdc++.h>
using namespace std;
long long n,ans=0,leng;
long long a[500010];
long long m,total;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=n;i>=1;i--){
		leng=1;
		total=0;
		for(int j=i-1;j>=1;j--){
			if(total+a[i]-a[j]<=m){
				total+=a[i]-a[j];
				leng++;
			}
			else{
				break;
			}
		}
		if(leng>ans)ans=leng;
	}
	printf("%lld",ans);
	return 0;
}
