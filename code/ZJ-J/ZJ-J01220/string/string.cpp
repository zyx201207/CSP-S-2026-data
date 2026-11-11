#include<bits/stdc++.h>
using namespace std;

int n,l,r;
long long a[210000];
char c[210000];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		cin>>c[i];
	}
	l=1;
	r=n;
	long long ans=0;
	while(l<r){
		if(c[l]==c[r]){
			if(a[l]<a[r]){
				a[r]=a[r]-a[l];
				++l;
			}
			else{
				a[l]=a[l]-a[r];
				--r;				
			}
		}
		else{
			if(a[l]<a[r]){
				ans=ans+a[l];
				a[r]=a[r]-a[l];
				++l;
			}
			else{
				ans=ans+a[r];
				a[l]=a[l]-a[r];
				--r;				
			}
		}
	}
	printf("%lld",ans);
	return 0;
} 
