#include<bits/stdc++.h>
using namespace std;
int n;
char c[1000005];
int a[1000005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
	}
	int l=0;
	int r=n-1;
	int sum=0;	
	while(l<r){
		if(c[l]==c[r]){
			if(a[l]>a[r]){
				a[l]-=a[r];
				r--;
			}else if(a[l]<a[r]){
				a[r]-=a[l];
				l++;
			}else{
				l++;
				r--;
			}
		}else{
			if(a[l]>a[r]){
				sum+=a[r];
				a[l]-=a[r];
				r--;
			}else if(a[l]<a[r]){
				sum+=a[l];
				a[r]-=a[l];
				l++;
			}else{
				l++;
				r--;
			}
		}
	}
	cout<<sum;
	return 0;
}