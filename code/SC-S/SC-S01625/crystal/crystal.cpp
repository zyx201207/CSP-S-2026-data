#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
ll n,m,a[N],pre[N];
int ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",a+i);
	sort(a+1,a+n+1);
	pre[1]=a[1];
	for(int i=2;i<=n;i++){
		pre[i]=pre[i-1]+a[i];
		int lf=1,rg=i-1;
		while(lf<rg-1){
			int mid=(lf+rg)>>1;
			if(a[i]*(i-mid+1)-(pre[i]-pre[mid-1])>m)lf=mid;
			else rg=mid;
		}
		if(a[i]*(i-lf+1)-(pre[i]-pre[lf-1])>m)lf++;
		ans=max(ans,i-lf+1);
	}
	printf("%d\n",ans);
	return 0;
}