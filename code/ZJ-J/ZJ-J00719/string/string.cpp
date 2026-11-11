#include<bits/stdc++.h>
using namespace std;
int n;
long long sum;
int a[200005];
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%s",&a[i],&c[i]);
	}
	int j=n,i=1;
	while(a[i]&&a[j]){
		if(a[i]>=a[j]){
			while(a[i]>=a[j]&&a[j]){
				if(c[i]!=c[j]) sum=sum+a[j];
				a[i]-=a[j];
				j--;
			}
			
		}
		if(a[i]<a[j]){
			if(a[i]){
				if(c[i]!=c[j]){
					sum=sum+a[i];
				}
				a[j]-=a[i];
				a[i]=0;
			}
			i++;
		}
	}
	printf("%lld",sum);
	return 0;
}
