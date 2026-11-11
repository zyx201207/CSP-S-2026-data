#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[1000010],ans;
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+n+1,cmp);
	ans=a[1];
	for(int i=2;i<=m;i++)ans&=a[i];
	printf("%lld",ans);
	return 0;
}

