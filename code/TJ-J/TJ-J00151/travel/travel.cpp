#include<bits/stdc++.h>
using namespace std;
string c,s,cc,ss;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c>>s>>cc>>ss;
	if(c[0]==cc[0]&&c[1]==cc[1]){
		cout<<"1";
	}
	else{
		cout<<"0000\n";
		return 0;
	}
	if(s[0]==ss[0]&&s[1]==ss[1]){
		cout<<"1";
	}
	else{
		cout<<"000\n";
		return 0;
	}
	if((s[2]>='A'&&s[2]<='C'&&ss[2]>='A'&&ss[2]<='C')||(s[2]>='D'&&s[2]<='E'&&ss[2]>='D'&&ss[2]<='E')){
		cout<<"1";
	}
	else{
		cout<<"00\n";
		return 0;
	}
	if((s[2]=='D'&&ss[2]=='C')||(s[2]=='C'&&ss[2]=='D')){
		cout<<"0\n";
		return 0;
	}
	int a=(int)s[2],b=(int)ss[2];
	if(a==b-1||a==b+1){
		cout<<"1\n";
	}
	else{
		cout<<"0\n";
	}
	return 0;
} 
