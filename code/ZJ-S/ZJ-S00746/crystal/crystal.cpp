#include<bits/stdc++.h>
#include<string>
#include<vector>
#define ll long long
using namespace std;
ll n,m,mi,mx,a[500005],l,r,mid,ans,fs;
bool fa,f;
bool test(ll s,ll sh){
	ll sum=0;
	ll k=lower_bound(a+1,a+n+1,s)-a;
	if(k-sh+1<1) return 0;
	for(int j=k-sh+1;j<=k;j++){
		if(sum>m) return 0;		
		sum+=s-a[j];
	}
	return 1;
}
bool check(ll x){
	for(int i=a[x];i<=a[n];i++)
		if(test(i,x)) return 1;
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	mi=1e13,mx=-1e13;
	cin>>n>>m;
	fa=f=1;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) if(a[i]-a[i-1]!=1) fa=0;
	for(int i=1;i<n;i++) if(a[i]-a[i-1]!=a[i+1]-a[i]) f=0;
	if(fa==1||f==1){
		for(int i=n;i>=1;i--){
			fs+=a[n]-a[i];
			if(fs>m){
				cout<<n-i;
				return 0;
			}
		}
	}
	else{
		sort(a+1,a+n+1);
		l=1,r=n;
		while(l<=r){
			mid=(l+r)/2;
			if(check(mid)){
				ans=mid;
				l=mid+1;
			}
			else r=mid-1;
		}
		cout<<ans;	
	}
	
}
