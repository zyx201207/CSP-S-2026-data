#include<bits/stdc++.h>

using namespace std;

#define ll long long

inline ll Rd(){
	ll x=0,f=1; int c=getchar();
	while (c<'0' || c>'9'){
		if (c=='-') f=-1;
		c=getchar(); 
	}
	while (c>='0'&&c<='9'){
		x=x*10+(c^'0');
		c=getchar();
	}
	return x*f;
}


ll n,m,a[500005],sum[500005];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ll n=Rd(),m=Rd();
	for (int i=1;i<=n;i++){
		a[i]=Rd();
	}
	sort(a+1,a+n+1);
	for (int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	int ans=-1;
	for (int i=1;i<=n;i++){
		int l=1,r=i-1,res=-1;
		while (l<=r){
			int mid=(l+r)>>1;
			ll tmp=(1ll*a[i]*(i-mid+1))-(sum[i]-sum[mid-1]);
			
			if (tmp<=m){
				res=mid;
				r=mid-1;
			}else{
				l=mid+1;
			}
		}
		ans=max(ans,i-res+1);
	}
	printf("%d\n",ans);
	return 0;
}
