#include<iostream>
using namespace std;
int main(){
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,l=0,r,sum=0;
	long long a[200010]={};
	char c[200010]={};
	cin>>n;
	r=n-1;
	for(int i=0;i<n;i=i+1){
		cin>>a[i]>>c[i];
	}
	while(l<r){
		if(c[l]!=c[r]){
			sum=sum+min(a[l],a[r]);
		}
		if(a[l]<a[r]){
			a[r]=a[r]-a[l];
			a[l]=0;
			l=l+1;
		}
		else if(a[l]>a[r]){
			a[l]=a[l]-a[r];
			a[r]=0;
			r=r-1;
		}
		else{
			a[l]=0;
			a[r]=0;
			l=l+1;
			r=r-1;
		}
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
