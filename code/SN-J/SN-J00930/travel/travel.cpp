#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a;
	string b;
	string c;
	string d;
	int e[10],f[10];
    cin>>a;
	cin>>b;
	cin>>c;
	cin>>d;
    if(a==c) cout<<1;
    else{
    	cout<<0;
    	cout<<0;
    	cout<<0;
    	cout<<0;
    	return 0;
	}
    e[0]=b[0]-'0';
    e[1]=b[1]-'0';
    f[0]=d[0]-'0';
    f[1]=d[1]-'0';
	if((e[0]==f[0])&&(e[1]==f[1])) cout<<1;
	else{
    	cout<<0;
    	cout<<0;
    	cout<<0;
    	return 0;
	} 
	if((b[2]=='A'||b[2]=='B'||b[2]=='C')&&(d[2]=='A'||d[2]=='B'||d[2]=='C')){
		cout<<1;
	}
	else if((b[2]=='D'||b[2]=='F')&&(d[2]=='D'||d[2]=='F')){
		cout<<1;
	}
	else{
    	cout<<0;
    	cout<<0;
    	return 0;
	} 
	if(b[2]=='A'&&d[2]=='B'){
		cout<<1;
	}
	else if(b[2]=='B'&&d[2]=='C'){
		cout<<1;
	}
	else if(b[2]=='D'&&d[2]=='F'){
		cout<<1;
	}
	else if(b[2]=='B'&&d[2]=='A'){
		cout<<1;
	}
	else if(b[2]=='C'&&d[2]=='B'){
		cout<<1;
	}
	else if(b[2]=='F'&&d[2]=='D'){
		cout<<1;
	}
	else cout<<0;
	return 0;
}
