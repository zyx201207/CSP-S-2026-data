#include<bits/stdc++.h>
using namespace std;
long long n,s,d;
long long a[210000];
char c[210000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		s+=a[i];
	}long long l=1,r=n;
	while(l<=r){
		if(a[l]==0){
			l++;
		}if(a[r]==0){
			r--;
		}if(c[l]==c[r]){
			if(a[l]>a[r]){
				a[l]-=a[r];
				a[r]=0;
			}else{
				a[r]-=a[l];
				a[l]=0;
			}
		}else{
			if(a[l]>a[r]){
				a[l]-=a[r];
				d+=a[r];
				a[r]=0;
			}else{
				a[r]-=a[l];
				d+=a[l];
				a[l]=0;
			}
		}
	}cout<<d;
	return 0;
}
