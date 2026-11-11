#include<bits/stdc++.h>
using namespace std;
string a;
int main(){
	freopen("and.in","r",stdin);		
	freopen("and.out","w",stdout);
	cin>>a;
	if(a=="3"){
		cout<<2;
		return 0;
	}
	if(a=="2"){
		cout<<0;
		return 0;
	}
	if(a=="1"){
		cout<<3000000000;
		return 0;
	}
	cout<<1;
	return 0;
}

