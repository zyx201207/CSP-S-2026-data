#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[500005];
int s[500005];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	int ans=1;
	for(int i=n;i>=1;i--){
		int l=1,r=i,idx=0;
		//cout<<i<<" ";
		while(l<=r){
			int mid=(l+r)>>1;
			if(s[i-1]-s[mid-1]>=(i-mid)*a[i]-m) idx=mid,r=mid-1;
			else l=mid+1;
		}
		//cout<<idx<<"\n";
		ans=max(ans,i-idx+1);
	}
	cout<<ans;
	return 0;
}