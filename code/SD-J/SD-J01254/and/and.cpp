#include <bits/stdc++.h>
using namespace std;
const int N=1e5*2+10;
int a[N];
int main (){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	if(m==1){
	sort(a+1,a+1+n);
	cout<<a[n];
	return 0;
	}
    if(m==n){
    	int sum=a[1];
    	for(int i=2;i<=n;i++){
    	sum=sum&a[i];
		}
		cout<<sum;
		return 0;
	}
	if(m==2){
		int max=INT_MIN;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[i]&a[j]>max)max=a[i]&a[j];
			} 
		}
		cout<<max;
		return 0;
	}else{
			int max=INT_MIN;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[i]&a[j]>max)max=a[i]&a[j];
			} 
		}
		cout<<max;
	}
	return 0; 
} 
