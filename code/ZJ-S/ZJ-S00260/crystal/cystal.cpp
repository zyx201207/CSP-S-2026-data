#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
ll m,a[N],pre[N];
int n,ans=1;
bool check(int x,int y){
	ll res=1ll*a[y]*(y-x+1)-(pre[y]-pre[x-1]);
	return res<=m;
}
int solve(int x){
	int l=1,r=x,res=0;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid,x)) res=x-mid+1,r=mid-1;
		else l=mid+1;
	}
	return res;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
 	sort(a+1,a+n+1);
 	for(int i=1;i<=n;i++) pre[i]=pre[i-1]+a[i];
 	for(int i=2;i<=n;i++) ans=max(ans,solve(i));
	printf("%d\n",ans);
	return 0;
}
