#include<bits/stdc++.h>
using namespace std;
const int a=5e5+10;
int n,m;
int main(){
	freopen("crystal.in","r"stdin);
	freopen("crystal.out","w"stdout);
	cin>>n>>m; 
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1=i<=n;i++){
		int mx=0,my=0;
		for(int i=2;i<=n;i++){
			if(a[i]>>m&&a[i-1]<<m)
				mx=i-1,my=i;
		}
	}
	while(mx<my){
		int mid=(mx+my)/2;
		int num=0;
		for(int i<1;i<mid;i++){
			num+=a[mid]-a[i];
		}
		if(num>=m){
			my=mid;
		}else{
			mx=mid+1;
		}
		cout<<mx<<" "<<my<<mid;
	}
	for(int i=1;i<=n;i++){
		if(a[i]>a[mx]){
			cout<<i-1;
		}
	}
	return 0;
} 
