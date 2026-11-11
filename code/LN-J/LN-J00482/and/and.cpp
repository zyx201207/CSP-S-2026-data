#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
int n,m;
ll a[N],f[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	f[0]=LLONG_MAX;
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++){
		for(int j=m;j>=1;j--)f[j]=max(f[j-1]&a[i],f[j]);
	}
	//for(int i=1;i<=m;i++)printf("%lld\n",f[i]);
	printf("%lld",f[m]);
	return 0;
}
