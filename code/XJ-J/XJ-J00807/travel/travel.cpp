#include<bits/stdc++.h>
using namespace std;
int a,b,e,f;
string c,d,g,h;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>c;
	cin>>b>>d;
	e=int(c[2])-65;
	f=int(d[2])-65;
	g=c[0]+c[1];
	h=d[0]+d[1];
	if(a==b){
		cout<<"1";
	}else{
		cout<<"0000";
		return 0;
	}
	if(g==h){
		cout<<"1";
	}else{
		cout<<"000";
		return 0;
	}
	if(e<3 && f<3 || e>=3 && f>=3){
		cout<<"1";
	}else{
		cout<<"00";
		return 0;
	}
	if(e+1==f || f+1==e){
		cout<<"1";
	}else{
		cout<<"0";
	}
	return 0;
}