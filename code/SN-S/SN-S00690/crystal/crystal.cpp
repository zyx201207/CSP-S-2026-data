#include<bits/stdc++.h>
using namespace std;
using ll=long long;
constexpr int N=5e5+10;
int n,l,r,mid,ans;
ll m,a[N],p[N];
int main(){
	freopen("crystal.in","r",stdin),freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=0;i<n;i++)scanf("%lld",&a[i]);
	sort(a,a+n);
	for(int i=0;i<n;i++)p[i]=a[i]+(i?p[i-1]:0);
	for(int i=0;i<n;i++){
		l=0,r=i;
		while(l<r){
			mid=(l+r)>>1;
			if(1ll*(i-mid+1)*a[i]-(p[i]-(mid?p[mid-1]:0))<=m)r=mid;
			else l=mid+1;
		}
		ans=max(ans,i-l+1);
	}
	printf("%d",ans);
	return 0;
}
//我就是上午不会 t4 的我又回来了。出场之后直接秒了。
//能打成什么样随便吧。 
//不是 t1 咋这么简单啊。 
