#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=500010;
int n,ans;
ll m,a[N],l,r=INT_MIN;
bool check(ll x){
	int tot=0;
	ll cnt=m;
	for(int i=n;i>=1;i--){
		if(a[i]>x) continue;
		else if(a[i]==x) tot++;
		else if(x-a[i]<=cnt){
			cnt=cnt-x+a[i];
			tot++;
		}
	}
	if(ans<tot){
		ans=tot;
		return 1;
	}else{
		return 0;
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		r=max(r,a[i]);
		l=min(l,a[i]);
	}
	sort(a+1,a+1+n);
	while(l<=r){
		ll mid=l+(r-l)/2;
		if(check(mid)){
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	printf("%d\n",ans);
	return 0;
}
