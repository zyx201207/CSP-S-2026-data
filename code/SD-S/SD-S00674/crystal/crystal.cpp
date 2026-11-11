#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,o,l,r;
ll m,d,s,a[500002];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
		sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		while(a[i]*(i-l-1)-d>m)
		d-=a[++l];
		o=max(o,i-l);
		d+=a[i];
	}
	printf("%d",o);
	return 0;
}
