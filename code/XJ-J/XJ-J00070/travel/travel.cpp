#include<iostream>
#include<cstdio>
#include<bits/stdc++.h>
#include<string>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin >> a >> b >> c >> d;
	bool a1=false,b1=false,c1=false;
	if(a==c){
		cout << 1;
		a1=true;
	}
	else{
		cout << 0;
	}
	if(b[0]==d[0]&&b[1]==d[1]&&a1){
		cout << 1;
		b1=true;
	}
	else{
		cout << 0;
	}
	if(b1&&((b[2]<='C'&&d[2]<='C')||(b[2]>='D'&&d[2]>='D'))){
		cout << 1;
		c1=true;
	}
	else{
		cout << 0;
	}
	if(c1&&((b[2]-d[2]==1||d[2]-b[2]==1)||((b[2]=='D'&&d[2]=='F')||(b[2]=='F'&&d[2]=='D')))){
		cout << 1;
	}
	else{
		cout << 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
