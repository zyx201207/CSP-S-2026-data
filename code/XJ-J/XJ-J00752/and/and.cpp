#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	long long a[1000000000000]={};
	int c=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-i-1;j++){
			if(a[j]<a[j+1]){
				swap(a[j],a[j+1]);
			}
		}
	}
	int l=0;
	for(int i=0;i<m;i++){
		l=l and a[i];
	}
	cout<<l;
return 0;
}