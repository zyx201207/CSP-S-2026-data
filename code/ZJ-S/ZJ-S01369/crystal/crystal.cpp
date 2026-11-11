#include<bits/stdc++.h>
using namespace std;
int n,ans;
long long a[500010],s[500010],m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		s[i]=a[i]+s[i-1];
		int r=i,l=1;
		while(l<r){
			int mid=(l+r)/2;
			if((i-mid+1)*a[i]-s[i]+s[mid-1]<=m) r=mid;
			else l=mid+1;
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	return 0;
}