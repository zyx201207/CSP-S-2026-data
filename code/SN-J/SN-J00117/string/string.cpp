#include<bits/stdc++.h>
using namespace std;
int main(){
	int n=0;
	int cnt=0;
	cin >> n;
	int a[n]={};
	char c[n]={};
	int b=0,d=0;
	for(int i=0;i<n;i++){
		cin >> a[i] >> c[i];
		b+=a[i];
	}
	string s;
	for(int i=0;i<b;i++){
		for(int j=0;j<a[i];j++){
			s[d]=c[i];
			d+=1;
		}
	}
	for(int i=0;i<b;i++){
		if(i==(b-1) && s[i]==s[0]){
			cout << 0;
			return 0;
		}
		if(s[i]==s[0]){
			continue;
		}else{
			break;
		}
	}
	d+=1;
	string s2,s3;
	for(int i=0;i<(d/2);i++){
		s2[i]=s[i];
	}
	int m=0;
	for(int i=(d/2);i<d;i++){
		s2[m]=s[i];
		m+=1;
	}
	for(int i=0;i<(d/2);i++){
		if(s2[i]==s3[i]){
			continue;
		}else{
			cnt+=1;
		}
	}
	cnt+=1;
	cout << cnt;
	return 0;
} 
