#include <bits/stdc++.h>
using namespace std;
long long a[10000000]={0},b[10000000]={0};
long long mx=-18e9;
int main(){
	freopen("and","r",stdin);
	freopen("and","w",stdout);
	long long n,m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		cout<<0;
		return 0;
	}
	if(m==n){
		int sum=a[1]&a[2];
		for(int i=3;i<=n;i++){
			sum=sum&a[i];
		}
		cout<<sum;
		return 0;
	}
	if(m==2){
		for(int i=1;i<n;i++){
			int g=a[i]&a[i+1];
			if(g>mx)mx=g;
		}
		cout<<mx;
		return 0;
	}
	
	return 0;
}