#include<bits/stdc++.h>
using namespace std;
const int N=2e5+1;
int n,m,a[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	int ans=(1<<30)-1;
	for(int i=n-m+1;i<=n;i++)ans&=a[i];
	printf("%d",ans);
	return 0;
}