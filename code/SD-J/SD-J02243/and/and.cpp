#include<bits/stdc++.h>
using namespace std;
int n,m;
long long x=0;
long long a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%lld",&a[i]);
	}
	if(m==1){
		for(int i=0;i<n;i++){
			x=max(x,a[i]);
		}
	}
	else if(m==n){
		x=a[0];
		for(int i=1;i<n;i++){
			x=x&a[i];
		}
	}
	else{
		sort(a,a+n);
		x=a[n-1];
		for(int i=n-2;i>=n-m;i--){
			x=x&a[i];
		}
	}
	printf("%lld",x);
	return 0;
}

