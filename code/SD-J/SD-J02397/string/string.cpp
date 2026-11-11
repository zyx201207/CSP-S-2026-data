#include<bits/stdc++.h>
using namespace std;
long long n,a[220000],p,l,ml,nl,k;
char c[220000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld %c",&a[i],&c[i]);
		ml+=a[i];
	}
	p=n;
	l=a[n];
	for(int i=1;i<=n;i++){
		nl+=a[i];
		long long h=a[i];
		if(nl>ml/2ll){
			h=a[i]-(nl-ml/2ll);
		}
		while(h){
			if(h<=l){
				l-=h;
				if(c[i]!=c[p]){
					k+=h;
				}
				h=0;
			}
			if(h>l){
				if(c[i]!=c[p]){
					k+=l;
				}
				h-=l;
				l=0;
			}
			if(l==0){
				p--;
				l=a[p];
			}
		}
		if(nl>=ml/2ll){
			break;
		}
	}
	printf("%lld",k);
	return 0;
}
