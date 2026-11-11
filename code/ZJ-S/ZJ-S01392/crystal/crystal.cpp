#include<bits/stdc++.h>
using namespace std;
const int N=500005;
typedef long long ll;
int n,pos;
ll m,l,r,mid,ans,cnt,sum;
ll a[N],d[N];
ll f,cha;
ll check(ll x){
	sum=0;
	for(int i=1;i<=x;i++){
		sum+=a[x]-a[i];
	}
	if(sum<=m) return 1;
	else return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	cha=a[2]-a[1];
	for(int i=3;i<=n;i++){
		if(a[i]-a[i-1]!=cha){
			f=1;
		}
	}
	sort(a+1,a+1+n);
	if(f==0){
		l=1;
		r=n;
		while(l<=r){
			mid=(l+r)/2;
			if(check(mid)){
				ans=mid;
				l=mid+1;
			}
			else r=mid-1;
		}
		printf("%lld",ans);
		return 0;
	}
	for(int i=n;i>=1;i--){
		ll cnt=m;
		pos=i-1;
		sum=1;
		while(cnt-(a[i]-a[pos])>=0&&pos>=1){
			cnt-=a[i]-a[pos];
			pos--;
			sum++;
		}
		ans=max(ans,sum);
	}
	printf("%lld",ans);
	return 0;
}