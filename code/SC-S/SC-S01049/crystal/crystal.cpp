#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n;
	long long m;
	long long c=0,d=0;
	int a[100000];
	int b[100000];
	cin>>n;
	cin>>m; 
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	sort(a,a+n);
	for(int i=0;i<n;i++){
		b[i]=a[i]-a[i+1];
	}
	sort(b,b+n);
	for(int i=0;i<n;i++){
		c+=b[i];
		if(c= -m){
			d = i;
			if(b[i]==0){
			    d=d+1;
		    }	
		}else if(c< -m){
			d=i-1;
			if(b[i]==0){
				d=d+1;	
			}	
		} 
    }
	cout<<d;
	return 0;
}