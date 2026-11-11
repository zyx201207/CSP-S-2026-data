#include<iostream>
#include<string>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long a=0;
	cin>>a;
	string n;
	for(long long i=0;i<a;i++){
		long long b=0;
		cin>>b;
		char c='\0';
		cin>>c;
		for(long long j=0;j<b;j++){
			n+=c;
		}
	}
	long long e=n.length();
	long long d=0;
	for(long long i=0;i<=e/2-1;i++){
		if(n[i]==n[e-1-i]){
			
		}else{
			d++;
		}
	}
	cout<<d;
	return 0;
} 
