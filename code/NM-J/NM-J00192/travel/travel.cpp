#include<bits/stdc++.h>
using namespace std;
int a,c;
string b,d;
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
cin>>a>>b>>c>>d;
if(b[2]=='F'){
	b[2]='E';
}
if(d[2]=='F'){
	d[2]='E';
}
if(a==c){
cout<<1;
if(b[0]*10+b[1]==d[0]*10+d[1]){
	cout<<1;
	if((b[2]=='E'&&d[2]=='D')||(b[2]=='D'&&d[2]=='E')||(b[2]!='E'&&b[2]!='D'&&d[2]!='E'&&d[2]!='D')){
		cout<<1;
		if((b[2]-'0')-(d[2]-'0')==1||(b[2]-'0')-(d[2]-'0')==-1){
			cout<<1;
		}else{
			cout<<0;
		}
	}else{
		cout<<"00";
	}
}else{
cout<<"000";
}
}else{
cout<<"0000";
}
return 0;
}

