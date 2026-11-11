#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
bool e,f,g,h;
bool z,x,y;
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
ios::sync_with_stdio(false);
cin>>a>>b>>c>>d;
if(a==c){
e=1;
z=1;
}
if(b[1]==d[1]&&b[0]==d[0]&&z==1){
f=1;
x=1;
}
if(x==1&&((b[2]>='A'&&b[2]<='C'&&d[2]>='A'&&d[2]<='C')||(b[2]>='D'&&b[2]<='F'&&d[2]>='D'&&d[2]<='F'))){
	g=1;
	y=1;
	}
	if(y==1&&((abs(b[2]-d[2])<=1)||(b[2]=='D'&&d[2]=='F')||b[2]=='F'||b[2]=='D')){
		h=1;
		}
		cout<<e<<f<<g<<h;
cin.tie(nullptr);
cout.tie(nullptr);
return 0;
}
