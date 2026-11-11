#include<bits/stdc++.h>
using namespace std;
long long sum=0;
long long n;
long long a[200009];
char b[200009];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	long long l=1;
	long long r=n;
	while(l<r){
		if(a[l]>a[r]){
			if(b[l]!=b[r]){
				sum+=a[r];
			}
			a[l]-=a[r];
			a[r]=0;
			r--;
		}else if(a[l]==a[r]){
			if(b[l]!=b[r]){
				sum+=a[l];
			}
			a[l]=0;
			a[r]=0;
			l++;
			r--;
		}else{
			if(b[l]!=b[r]){
				sum+=a[l];
			}
			a[r]-=a[l];
			a[l]=0;
			l++;
		}
	}
	cout<<sum<<endl;
	return 0;
}
