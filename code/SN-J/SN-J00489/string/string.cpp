#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int a[n],su=0,cn=0;
	char c[n];
	while(su<n){
		cin>>a[cn]>>c[cn];
		su+=a[cn];
		cn++;
	}
	int cnt=0,l=0,r=cn-1,ans=0;
	while(cnt<=n/2){
		if(c[l]==c[r]){
			cnt+=min(a[l],a[r]);
			a[l]-=min(a[l],a[r]);
			if(a[l]==0){
				l++;
			}
			a[r]-=min(a[l],a[r]);
			if(a[r]==0){
				r--;
			}
		}else{
			cnt+=min(a[l],a[r]);
			ans+=min(a[l],a[r]);
			if(a[l]==0){
				l++;
			}
			a[r]-=min(a[l],a[r]);
			if(a[r]==0){
				r--;
			}
		}
	}
	cout<<ans;
	return 0;
}
