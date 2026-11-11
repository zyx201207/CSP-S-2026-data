#include<bits/stdc++.h>
using namespace std;
long long n,m,ans=-1,a[500009],s[500009];
bool cmp(long long a,long long b){
	return a<b;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	for(long long i=1LL;i<=n;i++){
		long long l=1LL,r=i;
		while(l<r){
			long long mid=(l+r)/2LL;
			if((i-mid)*a[i]-s[i-1]+s[mid-1]>m) l=mid+1;
			else r=mid;
		}
		ans=max(ans,i-r+1);
	}
	cout<<ans<<endl;
	return 0;
}
