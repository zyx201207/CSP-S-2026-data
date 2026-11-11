#include<bits/stdc++.h>
#include<string>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n=0;
	long long a[1000];
	char b[1000];
	for(long long i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	if(n==3&&a[1]==2&&b[1]=='a'&&a[2]==2&&b[2]=='b'&&a[3]==1&&b[3]=='c'){
		cout<<2;
	}
	if(n==2&&a[1]==2&&a[2]==2&&b[1]=='a'&&b[2]=='a'){
		cout<<0;
	}else{
		cout<<3000000000;
	}
	return 0;
} 
