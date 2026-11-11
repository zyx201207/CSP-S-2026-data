#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,ans=0;
int a[200100];
char c[200100];
signed main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>a[i]>>c[i];
	}
	int l=1,r=n;
	while(l!=r) {
		if(l+1==r){
			if(c[l]!=c[r]){
				ans+=min(a[l],a[r]);
			}
			break;
		}
		if(a[l]>a[r]) {
			if(c[l]!=c[r]){
				ans+=a[r]; 
			}
			int sum=a[l]-a[r];
			r--;
			while(l!=r) {
				if(c[r]==c[l]) {
					if(a[r]>=sum) {
						a[r]-=sum;
						l++;
						break;
					} else {
						sum-=a[r];
						a[r]=0;
					}
				} else {
					if(a[r]>=sum) {
						a[r]-=sum;
						ans+=sum;
						l++;
						break;
					} else {
						ans+=a[r];
						sum-=a[r];
						a[r]=0;
					}
				}
				r--;
			}
		}else if(a[l]<a[r]) {
			if(c[l]!=c[r]){
				ans+=a[l]; 
			}
			int sum=a[r]-a[l];
			l++;
			while(l!=r) {
				if(c[r]==c[l]) {
					if(a[l]>=sum) {
						a[l]-=sum;\
						r--;
						break;
					} else {
						sum-=a[l];
						a[l]=0;
					}
				} else {
					if(a[l]>=sum) {
						a[l]-=sum;
						ans+=sum;
						r--;
						break;
					} else {
						ans+=a[l];
						sum-=a[l];
						a[l]=0;
					}
				}
				l++;
			}
		}else{
			if(c[l]!=c[r]){
				ans+=a[l];
			}
			l++;
			r--;
		}
	}
	cout<<ans;
	return 0;
}
