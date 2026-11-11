#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],f[200005],maxx=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		maxx=max(maxx,a[i]);
	}
	for(int i=0;i<=n;i++)f[i]=maxx;
	for(int i=1;i<=n;i++){
		f[i]=max(f[i-1],f[i-1]&a[i]);
	}
	printf("%lld",f[n]);
	return 0;
}
