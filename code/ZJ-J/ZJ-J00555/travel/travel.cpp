#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
bool fun(string a,string b){
	if((a[2]=='A'||a[2]=='B'||a[2]=='C')&&(b[2]=='A'||b[2]=='B'||b[2]=='C'))return 1;
	if((a[2]=='D'||a[2]=='F')&&(b[2]=='D'||b[2]=='F'))return 1;
	return 0;
}
bool sss(string a,string b){
	if(a[2]=='A'){
		if(b[2]=='B')return 1;
		return 0;
	}
	if(a[2]=='B'){
		if(b[2]=='A'||b[2]=='C')return 1;
		return 0;
	}
	if(a[2]=='C'){
		if(b[2]=='B')return 1;
		return 0;
	}
	if(a[2]=='D'){
		if(b[2]=='F')return 1;
		return 0;
	}
	if(a[2]=='F'){
		if(b[2]=='D')return 1;
		return 0;
	}
	return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a==c)cout<<1;
	else cout<<0;
	if(a==c&&b[0]==d[0]&&b[1]==d[1])cout<<1;
	else cout<<0;
	if(a==c&&b[0]==d[0]&&b[1]==d[1]&&fun(b,d))cout<<1;
	else cout<<0;
	if(a==c&&b[0]==d[0]&&b[1]==d[1]&&fun(b,d)&&sss(b,d))cout<<1;
	else cout<<0;
	return 0;
}
//8:49 AC 