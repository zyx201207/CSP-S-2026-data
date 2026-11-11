#include<bits/stdc++.h>
using namespace std;

long long a[1000000];

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long b=0,c=8000000,n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(b<a[i]){
			b=a[i];
		}
		if(c>a[i]){
			c=a[i];
		}
	}
	long long e=0;
	for(int i=0;i<n;i++){
		if(e<a[i]&&a[i]!=b){
			e=a[i];
		}
	}
	if(n==m){
		long long s=a[0];
		for(int i=1;i<n;i++){
			s^=a[i];
		}
		cout<<s;
		return 0;
	}
	if(m==2){
		long long d;
		d=b^c;
		cout<<d;
		return 0;
	}
	if(m==1){
		cout<<b;
		return 0;
	}
	if(m==n-1){
		long long ma=a[0];
		for(int i=1;i<n;i++){
			if(a[i]!=e){
				ma^=a[i];
			}
		}
		cout<<ma;
		return 0;
	}
	sort(a,a+n);
	long long gh=a[0],num=a[n];
	for(int i=1;i<m-1;i++){
		gh^=a[i];
	}
	num^=gh;
	cout<<num;	
	return 0;
} 
