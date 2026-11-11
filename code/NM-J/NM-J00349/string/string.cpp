#include<iostream> 
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("in.string","r",stdin);
	freopen("out.string","w",stdout);
	long long n=0;
	cin>>n;
	string a;
	for(long long i=0;i<n;i++){
		long long b=0;
		char c='\0';
		cin>>b>>c;
		for(long long j=0;j<b;j++){
			a+=c;
		} 
	} 
	long long t=0;
	for(long long i=0;i<= a.length()/2-1;i++){
		if(a[i]==a[a.length()-1-i]){
			
		}else{
			t++;
		}
	}cout<<t;
	
	
	
	return 0;
}
