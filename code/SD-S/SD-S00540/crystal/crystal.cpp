#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+10;
long long a[N],pre[N];
long long n,m;
int check(int l,int r);
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int as=0;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		pre[i]=pre[i-1]+a[i];
	}
//	for(int i=1;i<=n;i++){
//		long long t=0,p=i;
//		for(int j=i;j>=1;j--){
//			t+=a[i]-a[j];
//			if(t>m) break;
//			p=j;
//		}
////		cout<<i-p+1<<" ";
//		as=max(as,i-p+1);
//	}
//	cout<<"\n";
//	cout<<as;
	for(int i=1;i<=n;i++){
		int l=1,r=i,mid,ans=0;
		while(l<=r){
			mid=(l+r)>>1;
			if(check(mid,i)) r=mid-1,ans=mid;
			else l=mid+1;
		}
//		cout<<i-ans+1<<" ";
		as=max(as,i-ans+1);
	}
	cout<<as;
	return 0;
}
int check(int l,int r){
	if(1ll*(r-l+1)*a[r]-(pre[r]-pre[l-1])<=m) return 1;
	else return 0;
}
