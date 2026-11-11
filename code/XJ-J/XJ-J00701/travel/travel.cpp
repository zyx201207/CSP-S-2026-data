#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b,e,f;
	string c,d;
	cin>>a>>c>>b>>d;
	e=(c[0]-'0')*10+c[1]-'0';
	f=(d[0]-'0')*10+d[1]-'0';
	if(a==b){
		cout<<1<<endl;
	}else{
		cout<<"0000";
		return 0;
	}if(e==f){
		cout<<1;
	}else{
		cout<<"000";
		return 0;
	}if((c[2]=='A'&&(d[2]=='B'||d[2]=='C'))||(c[2]=='B'&&(d[2]=='A'||d[2]=='C'))||(c[2]=='C'&&(d[2]=='B'||d[2]=='A'))||(c[2]=='D'&&d[2]=='E')||(c[2]=='E'&&d[2]=='D')){
		cout<<1;
	}else{
		cout<<"00";
		return 0;
	}if((c[2]=='A'&&d[2]=='B')||(c[2]=='B'&&d[2]=='C')||(c[2]=='D'&&d[2]=='E')){
		cout<<1;
	}else{
		cout<<"0";
	}
} 
