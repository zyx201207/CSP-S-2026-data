#include <bits/stdc++.h>
using namespace std;

string _2(int a){//取二进制 
	string a2="";
	int cnt=0;
	while(a){
		a2[cnt]=a%2;
		a/=2;
		cnt++;
	}
	return a2;
}

int _2t(string a){
	int a1=0;
	int cnt=1;
	int l=a.length();
	for(int i=l-1;i>=0;i--){
		a1+=(a[i]-48)*cnt;
		cnt*=2;
	}
	return a1;
}

int main(){
	int n,m;
	cin>>n>>m;
	int a[200005]={};
	string a2[200005]={};
	for(int i=0;i<n;i++){
		cin>>a[i];
		a2[i]=_2(a[i]);
	}
}

/*
	按位与& 
*/
