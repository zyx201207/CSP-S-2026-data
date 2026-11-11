#include<bits/stdc++.h>
using namespace std;
long long n,m,a[100005],ans=0;
void f(int x,int t,long long s){
	if(x==m){
		ans=max(s,ans);
		return;
	}
	for(int i=t;i<n;i++){
		if(x==0){
			s=a[i];
		}
		f(x+1,i+1,s&a[i]);
	}
	return;
}
int main(){
	freopen("in.and","r",stdin);
	freopen("out.and","w",stdout);
	scanf("%lld%lld",&n,&m);
	if(n<=20){
		for(int i=0;i<n;i++){
			scanf("%lld",&a[i]);
		}
		f(0,0,0);
	}
	else if (n<=2000&&m==1){
		for(int i=0;i<n;i++){
			scanf("%lld",&a[i]);
			ans=max(a[i],ans);
		}
	}
	else if (n<=2000&&m==n){
		for(int i=0;i<n;i++){
			scanf("%lld",&a[i]);
			if(i==0){
				ans=a[i];
			}
			ans=ans&a[i];
		}
	}
	else if (n<=2000&&m==2){
		for(int i=0;i<n;i++){
			scanf("%lld",&a[i]);
		}
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}
	}
	printf("%lld",ans);
	return 0;
}
