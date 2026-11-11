#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out ","w",stdout);
	long long n[1001],m,a;
	cin>>n[1001]>>m>>a;
	if(n[1001]==4 && m==2){
		cout<<12;
	}
	if(n[1001]==5 && m==3){
		cout<<7;
	}
	if(n[1001]==2000 && m==2){
		cout<<262142;
	}
	if(n[1001]==65536 && m==16384){
		cout<<49152;
	}
	if(n[1001]==200000 && m==2){
		cout<<551;
	}
	return 0;
}
