#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[200005];
char c[200005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int l=1,r=n,ans=0;
	while(l<r){
		while(l<r&&a[l]>=a[r]){
			if(c[l]!=c[r]){
				ans+=a[r];
				a[l]-=a[r];
			}
			if(c[l]==c[r]){
				a[l]-=a[r];
			}
			r--;
		}
		while(l<r&&a[l]<a[r]){
			if(c[l]!=c[r]){
				ans+=a[l];
				a[r]-=a[l];
			}
			if(c[l]==c[r]){
				a[r]-=a[l];
			}
			l++;
		}
	}
	cout<<ans;
	return 0;
}