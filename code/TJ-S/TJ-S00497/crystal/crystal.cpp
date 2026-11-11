#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int l=1,r=n,ans=0;
	while(l<=r){
		int mid=(l+r)/2,x=m,ma=1;
		for(int i=mid-1;i>=1;i--){
			x-=a[mid]-a[i];
			if(x<0) break;
			ma++;
		}
		ans=max(ans,ma);
		if(x<0) r=mid-1;
		else l=mid+1;
	}
	cout<<ans;
	return 0;
}
