#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[2*100000+10];
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int mx=0;
	for(int i=1;i<=n-m;i++){
		int y=a[i];
		for(int j=1;j<=m;j++){
			y=y&a[i+j];
		}
		mx=max(mx,y);
	}
	cout<<mx;
}