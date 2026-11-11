#include<iostream>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long a=0;
	long long b=0;
	cin>>a>>b;
	long long t=0;
	for(long long i=0;i<a;i++){
		long long a=0;
		cin>>a;
		if(i==0){
			t=a;
		}
	}
	cout<<t;
	return 0;
} 
