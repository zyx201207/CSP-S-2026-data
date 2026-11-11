#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500005],s[500005];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		int l=1,r=i,sna=i;
		while(l<=r){
			int mid=(l+r)/2;
			if(a[i]*(i-mid+1)-(s[i]-s[mid-1])<=m){
				r=mid-1;
				sna=mid;
			}else{
				l=mid+1;
			}
		}
		ans=max(ans,i-sna+1);
	}
	cout<<ans;
	return 0;
}

