#include<bits/stdc++.h>
using namespace std;
int a[200007];
char b[200007];
int n;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>b[i];
	}
	long long gai=0;
	int l=0,r=n-1;
	while(l<r){
		if(b[l]!=b[r]){
			if(a[l]>=a[r]){
				gai+=a[r];
				a[l]-=a[r];
				a[r]=0;
			}
			else{
				gai+=a[l];
				a[r]-=a[l];
				a[l]=0;
			}
		}
		else{
			if(a[l]>=a[r]){
				a[l]-=a[r];
				a[r]=0;
			}
			else{
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
	cout<<gai;
	return 0;
} 
