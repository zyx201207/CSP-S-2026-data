#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char a,b,c,d;
	cin>>a>>b>>c>>d;
	if((a!='01'&&a!='16'&&c!='01'&&c!='16')||a==c){
		cout<<1111;
	}else if(a!=c&&b==d){
		cout<<1100;
	}else if(b!=d){
		cout<<1000;
	}else{
		cout<<0000;
	}
	return 0;
}
