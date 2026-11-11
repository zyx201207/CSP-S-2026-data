#include<bits/stdc++.h>
using namespace std;
int n,a[200010];
long long s;
char c[200010];
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {
		scanf("%d %c",&a[i],&c[i]); 
	}
	for(int i=1,j=n;i<=j;) {
		if(c[i]!=c[j]) {
			s=s+min(a[j],a[i]);
		}
		if(a[i]<a[j]) {
			a[j]-=a[i];
			i++;
		}
		if(a[i]==a[j]) {
			i++;
			j--;
		}
		if(a[i]>a[j]) {
			a[i]-=a[j];
			j--;
		}
	}
	printf("%lld",s);
	return 0;
}
