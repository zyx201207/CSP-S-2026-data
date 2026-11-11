#include<bits/stdc++.h>
using namespace std;
int a1,b1;
string a2,b2,a3,b3,a4,b4;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
cin>>a1>>a2>>b1>>b2;
if(a1!=b1){
    cout<<"0000";
    return 0;
}
cout<<"1";
a3+=a2[0];
a3+=a2[1];
b3+=b2[0];
b3+=b2[1];
if(a3!=b3){
	cout<<"000";
	return 0;
}
cout<<"1";
a4+=a2[2];
b4+=b2[2];
if( a4=="D" && b4!="F" || a4=="F" && b4!="D" || b4=="D" && a4!="F" || b4=="F" && a4!="D"){
	cout<<"00";
	return 0;
}
cout<<"1";
if(a4=="D"  && b4=="F" || a4=="F" && b4=="D" || a4=="A" && b4=="B" || a4=="B" && b4=="A" || a4=="B" && b4=="C" || a4=="C" &&b4=="B"){
	cout<<"1";
}else{
	cout<<"0";
}
return 0;
}
