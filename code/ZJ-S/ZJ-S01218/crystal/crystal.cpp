#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5e5+5;
ll n,m,a[N],l,r,ans,t[205];
bool f10=1,f13=1;
bool check(int x){
	ll cnt=0;
	for(int i=1;i<=x;i++) cnt+=a[x]-a[i];
	return m>=cnt;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(f10&&abs(a[i])<=100) t[a[i]+100]++;
		if(abs(a[i])>100) f10=0;
	}
	sort(a+1,a+n+1);
	for(int i=3;i<=n;i++) if(a[i]-a[i-1]!=a[i-1]-a[i-2]) f13=0;
	if(n<=5000){
		for(int i=1;i<=n;i++){
			ll sum=0;
			for(int j=i-1;j>0;j--){
				sum+=a[i]-a[j];
				if(sum>m){
					ans=max(ans,1LL*(i-j));
					break;
				}
			}
			if(sum<=m) ans=max(ans,1LL*i);
		}
	}else if(f10){
		for(int val=0;val<=200;val++){
			ll cnt=0,sum=0;
			for(int i=val;i>=0;i--){
				int da=val-i;
				sum+=t[i]*da;
				cnt+=t[i];
				if(sum>m){
					cnt-=(sum-m+da-1)/da;
					ans=max(ans,cnt);
					break;
				}
			}
			if(sum<=m) ans=max(ans,cnt);
		}
	}else if(f13){
		l=1,r=n;
		while(l<=r){
			ll mid=l+r>>1;
			if(check(mid)){
				ans=max(ans,mid);
				l=mid+1;	
			}
			else r=mid-1;
		}
	}
	printf("%lld\n",ans);
	return 0;
} 
