#include<bits/stdc++.h>
using namespace std;
const long long N=2e5+5;
long long n,a[N],k;
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	long long l=1,r=n;
	while(l<r){
		if(a[l]==a[r]){
			if(c[l]!=c[r])k+=a[l];
			a[l]=a[r]=0;
			l++;
			r--;
		}
		if(a[l]<a[r]){
			if(c[l]!=c[r])k+=a[l];
			a[r]-=a[l];
			a[l]=0;
			l++;
		}
		if(a[l]>a[r]){
			if(c[l]!=c[r])k+=a[r];
			a[l]-=a[r];
			a[r]=0;
			r--;
		}
	}
	cout<<k;
	return 0;
}
