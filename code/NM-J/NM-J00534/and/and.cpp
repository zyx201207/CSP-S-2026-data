#include<iostream>
using namespace std;
int b;
int main(){
	int m,n,c=0,a[100000] = {0};
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		b = max(b,a[i]);
		c = c&a[i];

	}
	if(m==1) cout<<b;
	if(m==n) cout<<0;
	return 0;

}
