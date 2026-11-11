#include<bits/stdc++.h>
using namespace std;
int n,m,a[200001];

int main(){
	cin>>n>>m;
	int b[m];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n-i+1;j++){
			if(a[j+1]>=a[j]){
				swap(a[j+1],a[j]);
			}
		}
	}
	for(int i=1;i<n;i++){
		cout<<a[i]and a[i+1];
	}
	return 0;
}
