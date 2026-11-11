#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
ll m,a[500005];
ll sum[500005];
int res;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",a+i);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	int i=1,j=1;
	while(i<=n&&j<=n){
		int len=j-i+1;
		int all=len*a[j];
		if(all-(sum[j]-sum[i-1])<=m){
			res=max(res,len);
			j++;
		}
		else{
			i++;
		}
	}
	printf("%d",res);
	return 0;
} 

