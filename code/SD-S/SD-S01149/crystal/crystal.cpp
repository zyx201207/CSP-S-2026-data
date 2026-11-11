#include<bits/stdc++.h>
using namespace std;


long long int n,a[505050],m,sum,cha;
bool dengcha=1;
bool find(int num){
	for(int i=1;i<=n-num+1;i++){
		sum=0;
		for(int j=i;j<=i+num-1;j++){
			sum+=(a[i+num-1]-a[j]);	
		}
		if(sum<=m){
			return 1;
		}
	}
	return 0;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i>=2){
			cha=a[2]-a[1];
			if(a[i]-a[i-1]!=cha){
				dengcha=0;
			}
		}
	}
	if(dengcha){
		m=floor(m/cha);
		for(int i=n;i>=1;i--){
			if((((1+i)*i)/2)<=m){
				cout<<i+1;
				return 0;
			}
		}
	}
	sort(a+1,a+n+1);
	int l=1,r=n;
	while(l<r){
		int mid=(l+r)>>1;
		if(find(mid)){
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	cout<<l-1;
	return 0;
} 
