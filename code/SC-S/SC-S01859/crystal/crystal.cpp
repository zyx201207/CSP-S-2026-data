#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int a[N],n,m;
int s[N];
int ans=0;
int get_val(int l,int r){
	return (r-l)*a[r]-(s[r-1]-s[l-1]);
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	for(int i=n;i>=1;i--){
		int l=1,r=i-1;
		while(l<=r){
			int mid=(l+r)/2;
	//		cout<<l<<" "<<r<<" "<<mid<<" "<<get_val(mid,i)<<"---00--\n";
			if(get_val(mid,i)<=m) r=mid-1;	
			else l=mid+1;
		}
	//	cout<<i<<" "<<a[i]<<" "<<l<<"------\n";
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	return 0;
}