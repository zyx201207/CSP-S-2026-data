#include<bits/stdc++.h>
using namespace std;
string s; 
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	long long l=0;
	cin>>n;
	for(long long i=0;i<n;i++){
		long long x;
		cin>>x;
		l+=x;
		char a;
		cin>>a;
		for(long long j=0;j<x;j++){
			s+=a;
		}
	}
	long long w=l/2,h=0;
	long long cut=0;
	for(long long j=0;j<l;j++){
		if(s[j]==s[j+1]){
			h++;
		}
	}
	if(h==l-1){
		cout<<"0"<<endl;
		return 0;
	}else{
		for(long long i=0;i<w;i++){
			if(s[i]!=s[l-1-i]){
				cut++;
			}
		}
		cout<<cut<<endl;
	}
	return 0;
} 
