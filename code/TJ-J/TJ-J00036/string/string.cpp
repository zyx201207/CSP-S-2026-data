#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	long long o=0,s,ans=0;
	char z;
	string hwc;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>s>>z;
		for(int j=0;j<s;j++){
			hwc[o]=z;
			o+=1;
		}
	}o-=1;
	for(int i=0;i<o/2;i++){
		if(hwc[i]!=hwc[o-i])	ans++;
	}cout<<ans;
	return 0;}
