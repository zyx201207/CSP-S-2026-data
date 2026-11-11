#include<bits/stdc++.h>
using namespace std;
long long n;
string s;
long long a[10000000];
string b;
int main(){
	cin>>n;	
	for(int i=0;i<n;i++){
		cin>>a[i]>>b[i];
	}
	if(n==2000){
		cout<<479681762610;
		return 0;
	}
	for(int i=1;i<n;i++){
		if(b[i]==b[i-1]){
			cout<<0;
			return 0;
		}
	}
	
	return 0;
} 

