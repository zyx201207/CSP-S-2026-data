#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int a[N],pre[N];
int n,m,ans=0;
bool check(int x,int id){
	int now=(id-x)*a[id];
	int y=pre[id]-pre[x];
//	printf("%lld %lld\n",now,y);
	if(now-y<=m)return true;
	return false;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		pre[i]=pre[i-1]+a[i];
		int l=0,r=i,now=INT_MAX;
		while(l<=r){
			int mid=(l+r)/2;
			if(check(mid,i)){
				r=mid-1;
				now=mid;
			}
			else l=mid+1;
		}
		ans=max(ans,i-now);
	}
	printf("%lld\n",ans);
	return 0;
}
