#include<bits/stdc++.h> 
using namespace std;
string r,x;
int _r,_x;
bool a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>_r>>r>>_x>>x;
	if(_r!=1&&_r!=16&&_r==_x&&_x!=1&&_x!=16){
		a=1;
	}
	else{
		a=0;
		cout<<a<<b<<c<<d;
		return 0;
	}
	if(r[0]+r[1]==x[0]+x[1]){
		b=1;
	}
	else{
		b=0;
		cout<<a<<b<<c<<d;
		return 0;
	}if(r[2]=='C'&&x[2]=='D'||x[2]=='C'&&r[2]=='D'){
		c=0;
		d=0;
		cout<<a<<b<<c<<d;
		return 0;
	}
	else{
		c=1;
	}if(r[2]-'A'==x[2]-'A'+1||r[2]-'A'==x[2]-'A'-1){
		d=1;
		cout<<a<<b<<c<<d;
		return 0;
	}
	else{
		d=0;
		cout<<a<<b<<c<<d;
		return 0;
	}
	return 0;
}
