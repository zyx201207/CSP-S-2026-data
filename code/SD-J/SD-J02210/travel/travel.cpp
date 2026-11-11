#include<bits/stdc++.h>
using namespace std;
char a[3],b[3],c[3],d[3];
int fun1(char x,char y){
	if(x=='A'&&y=='B') return 1;
	if(x=='B'&&y=='A') return 1;
	if(x=='B'&&y=='C') return 1;
	if(x=='C'&&y=='B') return 1;
	if(x=='D'&&y=='F') return 1;
	if(x=='F'&&y=='D') return 1;
	return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a[0]>>a[1]>>b[0]>>b[1]>>b[2]>>c[0]>>c[1]>>d[0]>>d[1]>>d[2];
	if(a[0]!=c[0]||a[1]!=c[1]){
		cout<<"0000";
		return 0;
	}
	cout<<"1";
	if(b[0]!=d[0]||b[1]!=d[1]){
		cout<<"000";
		return 0;
	}
	cout<<"1";
	if(((b[2]=='A'||b[2]=='B'||b[2]=='C')&&(d[2]=='D'||d[2]=='F'))||((d[2]=='A'||d[2]=='B'||d[2]=='C')&&(b[2]=='D'||b[2]=='F'))){
		cout<<"00";
		return 0;
	}
	cout<<"1";
	if(fun1(b[2],d[2])){
		cout<<"1";
	}else cout<<"0";
	return 0;
} 
