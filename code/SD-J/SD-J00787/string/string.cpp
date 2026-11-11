#include <bits/stdc++.h>
using namespace std;
long long c=0;
int a[200005],n;
char b[200005];
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>a[i]>>b[i];
	}
	int l=1,r=n;
	while(l<r) {
		if(a[l]>a[r]) {
			a[l]=a[l]-a[r];
			if(b[l]!=b[r]){
				c=c+a[r];
			}
			r--;
		}else if(a[l]==a[r]){
			if(b[l]!=b[r]){
				c=c+a[l];
			}
			l++;
			r--;
		}else{
			a[r]=a[r]-a[l];
			if(b[l]!=b[r]){
				c=c+a[l];
			}
			l++;
		}
	}
	cout<<c;
	return 0;
}
