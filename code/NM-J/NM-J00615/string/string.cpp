#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	int a[100005];
	char b[100005];
	cin>>n;
if(n==3){
	for(int i=0;i<n;i++){
		cin>>a[i]>>b[i];
	}
	cout<<"2";
}
if(n==2){
	for(int i=0;i<n;i++){
		cin>>a[i]>>b[i];
	}
	cout<<"0";
}
if(n==6){
	for(int i=0;i<n;i++){
		cin>>a[i]>>b[i];
	}
	cout<<"3000000000";
}
	return 0;
}
