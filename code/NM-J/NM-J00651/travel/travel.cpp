#include<bits/stdc++.h> 
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
		freopen("travel.out","w",stdout);
string a,b,c,d;
int q=0;
cin>>a>>b>>c>>d;
for(int i=0;i<2;i++){
	if(a[i]==c[i]){
	q++; } 
}
if(q==2){
	cout<<"1";
}
else{
	cout<<"0000";
	return 0;
}
q=0;
for(int i=0;i<2;i++){
	if(b[i]==d[i]){
	q++; } 
}
if(q==2){
	cout<<"1";
}
else{
	cout<<"000";
	return 0;
}
if((b[2]>='A'&&b[2]<='C')&&(d[2]>='A'&&d[2]<='C')||(b[2]>='D'&&b[2]<='F')&&(d[2]>='D'&&d[2]<='F')){
	cout<<"1";
}
else{
	cout<<"00";
	return 0;
}
if(((char(b[2]+1)==char(d[2]))||(char(b[2]-1)==char(d[2])))&&(b[2]!='C'&&d[2]!='D')&&(b[2]!='D'&&d[2]!='C')){
	cout<<"1";
}
else{
	cout<<"0";
} 
return 0;
}
