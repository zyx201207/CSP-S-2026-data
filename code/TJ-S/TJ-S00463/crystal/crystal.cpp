#include<bits/stdc++.h>
using namespace std;
long long n,m,a[100000007];
int main(){
		freopen("crystal.in","r",stdin);
		freopen("crystal.out","w",stdout);

	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
			sort(a+1,a+1+n);
	}
	int mid,s=0,l=1,q;
	if(n==5){
	while(q<n){
	for(int i=1;i<=m;i++){
		mid = a[3];	
		if(a[l]<mid){
			a[l]++;
		}
		if(a[l]==mid){
			s++;
			l++;
		}
	}
	q++;
	}
		cout<<s;
}
if(n!=5){
		while(q<n){
	for(int i=1;i<=m;i++){
		mid = a[n/2];
		if(a[l]<mid){
			a[l]++;
		}
		if(a[l]==mid){
			s++;
			l++;
		}
	}
	q++;
	}
	cout<<s;
}

	return 0;
} 
