#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500005],sum[500005];
int n,m;
bool check(int x){
	int kk=0x3f3f3f3f;
	for(int i=1;i+x-1<=n;i++){
		int l=i,r=i+x-1;
		int zong=a[r]*x;
		int k=sum[r]-sum[l-1];
		int c=zong-k;
		kk=min(c,kk);
	}
	return kk<=m;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	int l=1,r=n,ans=0;
	while(l<=r){
		int mid=(l+r)/2;
		if(check(mid)){
			l=mid+1;
			ans=max(ans,mid);
		}else{
			r=mid-1;
		}
	}
	cout<<ans;
	return 0;
}
