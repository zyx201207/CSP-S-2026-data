#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	long long an=0,num=0;
	string str="\0";
	for(int i=0;i<n;i++){
		long long x=0;
		char c=0;
		cin>>x>>c;
		num+=x;
		for(int i=0;i<x;i++){
			str+=c;
		}
	}
	string s1="\0",s2="\0";
	long long t=0;
	if(num%2==0){
		for(int i=0;i<num/2;i++){
			s1+=str[i];
		}
		for(int i=num/2;i<num;i++){
			s2+=str[i];
		}
	}else{
	//	cout<<num<<"\n";
		t=ceil(num/(double)2)-1;
	//	cout<<t<<"\n";
		for(int i=0;i<t;i++){
			s1+=str[i];
		}
		for(int i=t+1;i<num;i++){
			s2+=str[i];
		}
	}
//	cout<<str;
//	cout<<s1<<" "<<s2;

	for(int i=0;i<s1.length();i++){
		if (s1[i]!=s2[i]){
			an++;
		}
	}
	cout<<an;
	return 0;
}
