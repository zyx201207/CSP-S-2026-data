#include<bits/stdc++.h>
using namespace std;
int n,m,sum,sum1,a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	cin>>a[0];
	sum=a[0];
	for(int i=1;i<n;i++){
		cin>>a[i];
		if(m==n){
			sum=sum&a[i];
		}
	}
	if(m==n){
		cout<<sum;
	}else if(m==2){
		sum=0;
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				sum=max(sum,a[i]&a[j]);
			}
		}
		cout<<sum;
	}else if(m==1){
		sum=0;
		for(int i=0;i<n;i++){
			sum=max(sum,a[i]);
		}
		cout<<sum;
	}
	return 0;
	}
