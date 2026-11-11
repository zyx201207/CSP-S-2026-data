#include<bits/stdc++.h>
using namespace std;
const int N=5e5+9;
const long long MAX=1e18+2;
int n;
long long m,a[N],t,s[N],tot[N],mx;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d %lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	a[n+1]=MAX;
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	for(int i=n;i;i--){
		tot[i]=(a[i]==a[i+1])?(tot[i+1]+1):0;
	}
	for(int i=1;i<=n;i++){
		int l=1,r=i-1,ans=i;
		if(a[i]-a[i-1]>m){
			continue;
		}
		if(a[i]==a[i-1])continue;
		while(l<=r){
			long long mid=(l+r)>>1;
			long long sum=(i-mid)*a[i]-s[i-1]+s[mid-1];
			//if(i==4)cout<<i<<':'<<l<<','<<r<<' '<<sum<<' '<<ans<<endl;
			if(sum<=m){
				ans=mid;
				r=mid-1;
			}else {
				l=mid+1;
			}//if(i==4)cout<<i<<':'<<l<<','<<r<<' '<<sum<<' '<<ans<<endl;
		}
		//cout<<i<<' '<<ans<<endl;
		mx=max(i-ans+1+tot[i],mx);
	}
	cout<<mx;
	return 0;
}