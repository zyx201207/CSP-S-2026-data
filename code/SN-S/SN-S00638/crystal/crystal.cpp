#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[500001];
int ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)a[i]+=a[i-1];
//	cout<<a[i]<<' ';cout<<endl;
	for(int i=1;i<=n;i++){
		int l=1,r=i;
		while(l<r){
//			cout<<(a[i]-a[i-1])*(i)<<' '<<(a[i]-a[0])<<endl;
			int mid=(l+r)>>1;
//			cout<<i<<' '<<mid<<(a[i]-a[i-1])*(i-mid+1)<<' '<<(a[i]-a[mid-1])<<endl;
			if((a[i]-a[i-1])*(i-mid+1)-(a[i]-a[mid-1])<=m)r=mid;
			else l=mid+1;
		}
//		cout<<i<<' '<<l<<endl;
		ans=max(ans,i-l+1);
	}cout<<ans;
	return 0;
}
