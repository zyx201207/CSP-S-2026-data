#include<bits/stdc++.h>
using namespace std;
int n,a[200005];
long long s;
char b[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	int l=1,r=n;
	while(l<r){
		if(b[l]!=b[r]){
			if(a[l]==a[r]){
				s+=a[r];
				l++;
				r--;
			}
			else if(a[l]>a[r]){
				s+=a[r];
				a[l]=a[l]-a[r];
				r--;
			}
			else{
				s+=a[l];
				a[r]=a[r]-a[l];
				l++;
			}
		}
		else{
			if(a[l]==a[r]){
				l++;
				r--;
			}
			else if(a[l]>a[r]){
				a[l]=a[l]-a[r];
				r--;
			}
			else{
				a[r]=a[r]-a[l];
				l++;
			}
		}
	}
	cout<<s;
	return 0;
}
