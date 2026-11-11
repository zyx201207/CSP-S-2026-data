#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	long a;
	long long ct=0,cc=0;
	char c;
	string b;
	for(long long i=0;i<n;i++){
		cin>>a>>c;
		for(long long j=cc;j<a+cc;j++){
			b[j]=c;
		}
		cc+=a;
	}
	if(cc%2==1){
		for(long long i=0,j=cc-1;i<cc/2,j>cc/2;i++,j--){
			if(b[i]!=b[j])
				ct++;
		}
	}
	else{
		for(long long i=0,j=cc-1;i<cc/2,j>=cc/2;i++,j--){
			if(b[i]!=b[j])
				ct++;
		}
	}
	cout<<ct;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
