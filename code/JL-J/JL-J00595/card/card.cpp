#include<bits/stdc++.h>
using namespace std;
int main(){
	long long n,m;
	int a[100000];
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%lld",&n);
	scanf("%lld",&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++) printf("%d",&a[i]);
	return 0;
}
