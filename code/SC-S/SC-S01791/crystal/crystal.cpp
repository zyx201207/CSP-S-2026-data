#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,m,a[N],s[N],ans=1;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+(a[i]-a[i-1])*(i-1);
		int l=1,r=i;
		while(l<=r){
			int mid=(l+r)/2;
			int x=s[i]-s[mid]-(a[i]-a[mid])*(mid-1);
			if(x>m)l=mid+1;
			else r=mid-1;
		}
		ans=max(ans,i-r);
	}
	cout<<ans;
	return 0;
}