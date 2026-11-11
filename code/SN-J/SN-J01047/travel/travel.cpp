#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
void dk(){
	if(a!=c){
		cout<<"0000";
		return;
	}
	string s1=b.substr(0,2);
	string s2=d.substr(0,2);
	char ca=b[2];
	char cb=d[2];
	if(s1!=s2){
		cout<<"1000";
		return;
	}
	if((ca<='C')!=(cb<='C')){
		cout<<"1100";
		return;	
	}
	int dx=ca-cb;
	if(dx!=1&&dx!=-1){
		cout<<"1110";
		return;
	}
	cout<<"1111";
	return;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	dk();
} 
