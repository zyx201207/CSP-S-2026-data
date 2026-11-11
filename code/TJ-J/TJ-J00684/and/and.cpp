#include<bits/stdc++.h>
using namespace std;
int n,m;
int main(){
	cin>>n>>m;
	long long mx=0,x=0;
	for(int i=0;i<n;i++){
		cin>>x;
		mx=max(mx,x);
	}
	cout<<mx<<endl;
	retyrn 0;
} 
