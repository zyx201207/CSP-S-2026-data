#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("and.in","r",stdin);
	//freopen("and.out","w",stdout);
	long long n,m,a[20005],sum=-1000;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(m==1){
		for(int i=0;i<n;i++){
			sum=max(sum,a[i]);
		}
		cout<<sum;
	}else if(m==2){
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				int x=int((a[i])and(a[j]));
				cout<<x;
			}
		}
		cout<<sum;
	}else if(m==3){
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				for(int k=j+1;k<n;k++){
					int x=(a[i])and(a[j])and(a[k]);
					if(sum<x){
						sum=x;
					}
				}
			}
		}
		cout<<sum;
	}
	
	return 0;
} 
