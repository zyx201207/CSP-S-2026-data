//ËÎÐûµÂ SN-S00533 
#include<bits/stdc++.h>
using namespace std;
long long n,m,a[100000000001],b;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	b=a[2]/a[1];
	if(b==1){
		if(m%2==0){
			if(n>m/2+1){
				cout<<m/2+1;
			}else{
				cout<<n;
			}	
		}else{
			if(n>(m+1)/2+1){
				cout<<(m+1)/2+1;
			}else{
				cout<<n;
			}
		}
	}else{
		if(m%b==0){
			if(n>m/b){
				cout<<m/b;
			}else{
				cout<<n;
			}
		}else{
			if(n>m/b){
				cout<<m/2-1;
			}else{
				cout<<n;
			}
		}
	}
	return 0;
}
