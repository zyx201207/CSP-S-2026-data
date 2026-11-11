#include<bits/stdc++.h>
using namespace std;
int max_n(int &a[]){
	int m,n;
	m=a[0];
	n=0
	for(int i=1;i<sizeof(a)/sizeof(a[0]);i++){
		if(a[i]>a[n]){
			m=a[i];
			n=i;
		}
	}
}
int main(){
	int b,c,a[200005];
	cin>>b>>c;
	for(int i=0;i<b;i++){
		cin>>a[i];
	}
	cout<<max[a];
}
