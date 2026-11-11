#include<iostream>
#include<stdio.h>
#include<string>
#include<cmath>
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n=0,num=0;
	cin>>n;
	string S_L; 
	char s[n];
	long sum[n];
	for(int i=0;i<n;i++){
		cin>>sum[i]>>s[i];
		for(int k=0;k<sum[i];k++){
			S_L+=s[i];
		}
	}
	int l=S_L.size();
	for(int i=0;i<l;i++){
		if(!(S_L[i]==S_L[l-i-1])){
			num++;
		}
	}
	cout<<num;
	fclose(stdin);
	fclose(stdout);	
	return 0;
} 
