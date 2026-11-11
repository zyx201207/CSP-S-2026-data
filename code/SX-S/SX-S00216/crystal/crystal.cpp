#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,m;
int a[N],s[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]+a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	int ans=0;
	int l=1,r=n;
	while(l<r){
		int mid=(l+r)/2;
		int sum=mid*a[mid];
		int b=sum-s[mid];
		if(b>m){
			r=mid;
		}else{
			l=mid+1;
			ans=max(ans,mid);
		}
	}
	cout<<ans;
	return 0;
}