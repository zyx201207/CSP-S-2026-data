#include<bits/stdc++.h>
using namespace std;
string c,s,cc,ss;
long long a,b,aa,bb,x,y;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c>>s>>cc>>ss;
	for(int i=0;i<2;i++){
		a*=10;
		a+=c[i]-'0';
		aa*=10;
		aa+=cc[i]-'0';
	}
	if(a==aa){
		cout<<1;
	}else{
		cout<<"0000 ";
		return 0;
	}
	for(int i=0;i<2;i++){
		b*=10;
		b+=s[i]-'0';
		bb*=10;
		bb+=ss[i]-'0';
	}
	if(b==bb){
		cout<<1;
	}else{
		cout<<"000 ";
		return 0;
	}
	x=s[2]-'A';
	y=ss[2]-'A';
	if(x>2&&y>2||x<=2&&y<=2){
		cout<<1;
	}else{
		cout<<"00";
		return 0;
	}
	if(abs(x-y)==1){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0; 
}
