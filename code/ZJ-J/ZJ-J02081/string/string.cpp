#include<bits/stdc++.h>
using namespace std;
int n,l,r;
long long a[200005];
char b[200005];
long long ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	l=1,r=n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	while(l<r){
		if(int(b[l])!=int(b[r])){
			if(a[l]==a[r]){
				ans=ans+a[l];
				l++;
				r--;
			}
			else if(a[l]<a[r]){
				ans=ans+a[l];
				a[r]=a[r]-a[l];
				l++;
			}
			else{
				ans=ans+a[r];
				a[l]=a[l]-a[r];
				r--;
			}
		}
		else{
			if(a[l]==a[r]){
				l++;
				r--;
			}
			else if(a[l]<a[r]){
				l++;
			}
			else{
				r--;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
