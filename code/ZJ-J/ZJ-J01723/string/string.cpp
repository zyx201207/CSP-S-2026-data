#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","w",stdin);
	freopen("string.out","r",stdout);
	long long n,a;
	cin>>n;
	string S="";
	string s;
	for(long long i=1;i<=n;i++){
		cin>>a>>s;
		for(long long j=1;j<=a;j++){
			S=S+s;
		}
	}
	long long num=S.size();
	long long cnt=0;
	string H1="",H2=""; 
	if(num%2 == 0){
		for(long long p=num/2-1;p>=0;p--){
			H1=H1+S[p];
		}
		for(long long q=num/2;q<num;q++){
			H2=H2+S[q];
		}
		if(H1!=H2){
			for(long long n=0;n<num/2;n++){
				if(H1[n] != H2[n]){
					cnt++;
				}
			}
		}
	}else{
		for(long long p=num/2-1;p>=0;p--){
			H1=H1+S[p];
		}
		for(long long q=num/2+1;q<num;q++){
			H2=H2+S[q];
		}
		if(H1!=H2){
			for(long long n=0;n<num/2;n++){
				if(H1[n] != H2[n]){
					cnt++;
				}
		}
		}
	}
	cout<<cnt;
	return 0;
}
