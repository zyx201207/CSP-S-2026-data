#include<bits/stdc++.h>
#define int long long
using namespace std;

int a[500005],s[500005];

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
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
	for(int i=n;i>=1;i--){
		int l=0,r=i-1;
		while(l<=r){
			int mid=(l+r)/2;
			int sum=a[i]*mid-(s[i-1]-s[i-mid-1]);
			if(sum<=m){
				l=mid+1;
				ans=max(ans,mid);
			}
			else{
				r=mid-1;
			}
		}
	}
	
	cout<<ans+1;
	
	return 0;
}