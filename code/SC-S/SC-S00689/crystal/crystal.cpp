#include<bits/stdc++.h>
using namespace std;
struct s{
	int p,l;
}d[500100];
long long a[500100],n,m,ans=1,k;
int main(){
	int t1=1,t2=1;
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(a[i]!=i) t1=0;
	}
	sort(a+1,a+1+n);
	for(int i=4;i<=n;i++){
		if(a[i]-a[i-1]!=a[i-2]-a[i-3]){
			t2=0;
			break; 
		}
		else{
			k=a[i]-a[i-1];
		}
	}
	if(t1){
		for(int i=1;i<n;i++){
			if(m>=i) ans++;
			else break;
			m-=i;
		} 
		printf("%lld",ans);
		return 0;
	}
	if(t2){
		for(int i=1;i<n;i++){
			if(m>=i*k) ans++;
			else break;
			m-=i*k;
		} 
		printf("%lld",ans);
		return 0;
	}
	for(int i=1;i<n;i++){
		long long f=1,m1=m;
		for(int j=i-1;j>=1;j--){
			if(m1>=a[i]-a[j]) f++;
			else break;
			m1-=a[i]-a[j];
		}
		ans=max(ans,f);
	} 
	printf("%d",ans);
	return 0; 
} 