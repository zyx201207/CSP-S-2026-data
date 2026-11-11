#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],cnt=0;
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%ld",&n);
	for(long long i=1;i<=n;i++){
		scanf("%ld%s",&a[i],&c[i]);
	}
	long long h=1;
	for(long long j=n;j>0;j--){
		if(a[j]==a[h]&&c[j]==c[h]){
			continue;
		}else{
			if(c[j]==c[h]){
				if(c[j-1]==c[j]&&c[h+1]==c[h]){
					if(a[j-1]+a[j]==a[1]+a[h+1]){
						continue;
					}else{
						if(a[j-1]+a[j]>a[1]+a[h+1]){
							if(a[h+2]>=(a[j-1]+a[j]-a[1]-a[h+1])){
								a[h+2]=a[h+2]-(a[j-1]+a[j]-a[1]-a[h+1]);
								a[j-1]=a[j-1]-(a[j-1]+a[j]-a[1]-a[h+1]);
							}else{
								a[h+3]=a[h+3]+a[h+2]-(a[j-1]+a[j]-a[1]-a[h+1]);
							}
						}else{
							
						}
					}
				}
			}
		}
	}
	return 0;
}
