#include <bits/stdc++.h>
using namespace std;
string s,ss,c,cc,a="0000";
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s>>ss>>c>>cc;
	if(s!=c){
		cout<<a;
		return 0;
	}
	else a[0]='1';
	if(ss.substr(0,2)!=cc.substr(0,2)){
		cout<<a;
		return 0;
	}
	else a[1]='1';
	if((ss.substr(2,1)>"C"&&cc.substr(2,1)<="C")||(ss.substr(2,1)<="C"&&cc.substr(2,1)>"C")){
		cout<<a;
		return 0;
	}
	else a[2]='1';
	if((cc.substr(2,1)=="C"&&ss.substr(2,1)=="B")||(cc.substr(2,1)=="B"&&ss.substr(2,1)=="C")||(cc.substr(2,1)=="B"&&ss.substr(2,1)=="A")||(cc.substr(2,1)=="A"&&ss.substr(2,1)=="B")||(cc.substr(2,1)=="D"&&ss.substr(2,1)=="F")||(cc.substr(2,1)=="F"&&ss.substr(2,1)=="D")){
		a[3]='1';
	}
	else{
		cout<<a;
		return 0;
	}
	cout<<a;
	return 0;
}
