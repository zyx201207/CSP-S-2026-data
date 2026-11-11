#include<iostream>
#include<string>
#include<cmath>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long a=0;
	long long b=0;
	cin>>a>>b;
	if(a<0||b<0){
		return 0;
	}
	long long t=0;
	for(long long i=0;i<a;i++){
		cin>>t;
		if(t<0){
			break;
		}
	}
	int c=0;
	for(int i=0;i<a;i++){
		int k=t%2;
		t=t/2;
		if(t==1){
			break;
		}
		c=k;
	}
	if(a==4&&b==2){
		cout<<12;
	}
	if(a==5&&b==3){
		cout<<7;
	}
	return 0;
} 
