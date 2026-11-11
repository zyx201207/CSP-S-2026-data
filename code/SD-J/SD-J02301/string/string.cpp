#include <bits/stdc++.h>
using namespace std;
long long n,a[200005],sum=0,l=1,r;
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	r=n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	while(l<r){
		if(c[l]==c[r]){
			if(a[l]>a[r]){
				a[l]-=a[r];
				a[r]=0;
			}
			else{
				a[r]-=a[l];
				a[l]=0;
			}
		}
		else{
			if(a[l]>a[r]){
				sum+=a[r];
				a[l]-=a[r];
				a[r]=0;
			}
			else{
				sum+=a[l];
				a[r]-=a[l];
				a[l]=0;
			}
		}
		if(a[l]==0){
			l++;
		}
		if(a[r]==0){
			r--;
		}
	}
	cout<<sum;
	return 0;
}
