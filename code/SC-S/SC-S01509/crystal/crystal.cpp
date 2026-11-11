#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+100;
int n,ans;ll a[N],m,pre[N];
ll query(int l,int r){
	return pre[r]-pre[l-1];
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d %lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)pre[i]=pre[i-1]+a[i];
	for(int i=1,j=1;i<=n;i++){
		while(j<i&&a[i]*(i-j+1)-query(j,i)>m)j++;
		ans=max(ans,i-j+1);
	}
	printf("%d\n",ans);
	return 0;
}