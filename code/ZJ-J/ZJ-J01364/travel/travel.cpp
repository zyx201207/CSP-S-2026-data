#include<bits/stdc++.h>
using namespace std;
void open(string s){
	if(!s.size())return;
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}
string a,b,c,d;
string ans;
int main(){
	open("travel");
	cin>>a>>b>>c>>d;
	if(a==c&&a!="01"&&a!="06")ans=ans+'1';
	else{
		cout<<"0000"<<endl;
		return 0;
	}
	string xs;
	xs=xs+b[0];
	xs=xs+b[1];
	string ys;
	ys=ys+d[0];
	ys=ys+d[1];
	if(xs==ys)ans=ans+'1';
	else{
		cout<<"1000"<<endl;
		return 0;
	}
	if((b[2]=='C'&&d[2]=='D')||(b[2]=='D'&&d[2]=='C')){
		cout<<"1100"<<endl;
		return 0;
	}else{
		ans=ans+'1';
	}
	if(abs(int(b[2]-d[2]))==1)ans=ans+'1';
	else{
		cout<<"1110"<<endl;
		return 0;
	}
	cout<<ans;
	return 0;
}
