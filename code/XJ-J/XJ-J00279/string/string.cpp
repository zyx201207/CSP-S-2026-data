#include<bits/stdc++.h>
using namespace std;
long long a[1000000],a1[1000000];
string b;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n=0,d=0,c1=0,z=0,t=0;
	char c;
	cin>>n;
	if(n==1){
		cout<<0;
		return 0;
	}
	
	for(int i=0;i<n;i++){
		cin>>a[i]>>b[i];
		c=b[0];
		if(b[i]!=c){
			d=1;
		}
	}
	if(n==2&&b[0]==b[1]){
		cout<<0;
		return 0;
	}
	else if(n==2){
		cout<<min(a[0],a[1]);
		return 0;
	}
	else{
		if(d==1){
			cout<<1;
		}
		else{
			cout<<0;
		}
	}
	return 0;
}

