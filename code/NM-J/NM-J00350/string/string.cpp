#include<iostream>
#include<string>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
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
	long long e=a.length();
	for(long long i=0;i<=e/2-1;i++){
		if(a[i]==a[e-1-i]){
			
		}
		else{
			t++;
		}
	}
	cout<<t;
	return 0;
} 
