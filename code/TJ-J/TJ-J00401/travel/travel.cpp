#include<bits/stdc++.h>
//asd
using namespace std;
int check(char a){
	if(a=='A'||a=='B'||a=='C'){
		return 1;
	}else return 2;
}
//02 01A 02 01B
//01 012 01 012
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;cin>>a>>b>>c>>d;
	if(a==c)cout<<1;
	else cout<<0;
	if(b[0]==d[0]&&b[1]==d[1]&&a==c)cout<<1;
	else cout<<0;
	if(check((char)b[2])==check((char)d[2])&&a==c&&b[0]==d[0]&&b[1]==d[1])cout<<1;
	else cout<<0;
	if(check((char)b[2])==check((char)d[2])&&a==c&&(b[2]-d[2]==1 || b[2]-d[2]==-1)&&b[0]==d[0]&&b[1]==d[1])cout<<1;
	else cout<<0; 
	//tj-j00401
	//
	return 0;
} 
