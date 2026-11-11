#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],pre[500010],ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) pre[i]=pre[i-1]+(i-1)*(a[i]-a[i-1]);
	for(int i=1;i<=n;i++)
		if(pre[i]<=m) ans=i;
	cout<<ans;
	return 0; 
}
