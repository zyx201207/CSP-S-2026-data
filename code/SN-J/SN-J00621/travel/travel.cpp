#include<bits/stdc++.h>
using namespace std;
int main(){
	int a,c;
	string b,d;
	cin>>a>>b>>c>>d;
	int w=0;
	if(a==c){
		cout<<"1";
		w=1;
	} 
	else cout<<"0";
	//cout<<b[0]+<<endl;

	if(b[0]==d[0]&&b[1]==d[1]&&w==1) cout<<"1";
	else cout<<"0";
	int f=0;
	if(b[2]<='C'&&d[2]<='C'&&w==1) f=1;
	else if(b[2]>='D'&&d[2]>='D'&&w==1) f=1;
	if(b[0]!=d[0]||b[1]!=d[1]&&w==1) f=0;
	cout<<f;
	int q=1;
	if(b[2]=='A'&&d[2]=='C') q=0;
	if(b[2]=='C'&&d[2]=='A') q=0;
	if(f==1&&q==1) cout<<"1";
	else cout<<"0";
}
