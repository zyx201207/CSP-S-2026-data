#include<bits/stdc++.h>
using namespace std;

int a,b;
string a1,b1;
bool check1=false,check2=false,check3=false;
int main(){
//	freopen("travel.in","r",stdin);
//	freopen("travel.out","w",stdout);
	cin>>a>>b;
	if(a==b){
		cout<<1;
		check1=true;
	}
	else{
		cout<<"0000";
		return 0;
	}
	string lina,lind;
	lina=a1[0]+a1[1];
	lind=b1[0]+b1[1];
	if(a=b){
		cout<<1;
		check2=true;
	}
	else{
		cout<<"1000";
		return 0;
	}
	if((a[2]>='A'&&a[2]<='C')&&(b[2]>='B'&&b[2]<='D')){
	cout<<1;
		check3=true;
	}
	else{
		cout<<"1100";
		return 0;
	}
	return 0;
}
