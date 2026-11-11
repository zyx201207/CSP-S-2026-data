#include<bits/stdc++.h>
using namespace std;
int n,l,r;
long long ans,a[200005];
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	l=1;
	r=n;
	while(l<r){
		if(a[l]>=a[r]){
			if(c[l]!=c[r]){
				ans=ans+a[r];
			}
			a[l]=a[l]-a[r];
			a[r]=0;
			r--;
		}
		else{
			if(c[l]!=c[r]){
				ans=ans+a[l];
			}
			a[r]=a[r]-a[l];
			a[l]=0;
			l++;
		}
	}
	cout<<ans<<endl;
	return 0;
}
