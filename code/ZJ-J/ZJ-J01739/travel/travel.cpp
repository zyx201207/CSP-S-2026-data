#include<bits/stdc++.h>
using namespace std;
string s,xs;
int c,xc;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c>>s>>xc>>xs;
	if(c!=xc){
		cout<<"0000";
		return 0;
	}
	cout<<"1";
	int r=(s[0]-'0')*10+(s[1]-'0');
	int x=(xs[0]-'0')*10+(xs[1]-'0');
	if(r!=x){
		cout<<"000";
		return 0;
	}
	cout<<"1";
	if((s[2]<='C'&&xs[2]<='C')||(s[2]>'C'&&xs[2]>'C')){
		cout<<"1";
		if(s[2]+1==xs[2]||s[2]-1==xs[2]){
			cout<<"1";
			return 0;
		}
		cout<<"0";
		return 0;
	}
	cout<<"00";
	return 0;
}
