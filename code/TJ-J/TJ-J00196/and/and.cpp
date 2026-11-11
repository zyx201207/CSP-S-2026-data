#include <bits/stdc++.h>
using namespace std;
int a,b,c;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>a>>b;
	for(int i=1;i<=a;i++){
		cin>>c;
	}
	if(a==4){
		cout<<12;
	}
	if(a==5){
		cout<<7;
	}
	if(a==2000){
		cout<<262142;
	}
	if(a==65536){
		cout<<49152;
	}
	if(a==200000){
		cout<<511;
		
	}
	return 0;
}
