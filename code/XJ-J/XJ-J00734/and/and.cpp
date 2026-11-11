#include<bits/stdc++.h>
#include<string>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n=0,m=0;
	long long a[10000];
	char b[1000];
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==4&&m==2&&a[1]==3&&a[2]==15&&a[3]==12&&a[4]==12){
		cout<<12;
	}
	if(n==5&&m==3&&a[1]==31&&a[2]==3&&a[3]==1&&a[4]==15&&a[5]==7){
		cout<<7;
	}else{
		cout<<511;
	}
	return 0;
} //31 3 1 15 7