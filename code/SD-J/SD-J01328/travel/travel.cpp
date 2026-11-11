#include<bits/stdc++.h>
using namespace std;
string che1,che2,zuo1,zuo2;
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
ios::sync_with_stdio(false);
cin.tie(0);
cin>>che1>>zuo1>>che2>>zuo2;
if(che1!=che2){
	cout<<"0000";
	return 0;
}
else {
	cout<<"1";
	if(zuo1[0]==zuo2[0]&&zuo1[1]==zuo2[1]){
		cout<<1;
		int bian1=zuo1[2]-64,bian2=zuo2[2]-64;
		int pan1,pan2;
		if(bian1==1||bian1==2||bian1==3)pan1=0;
		else pan1=1;
		if(bian2==1||bian2==2||bian2==3)pan2=0;
		else pan2=1;
		if(pan1==pan2){
			cout<<"1";
			int pian=bian1-bian2;
			if(pian<0)pian=-pian;
			if(((bian1<=3&&bian2<=3)&&pian==1)||(bian1>3&&bian2>3)){
				cout<<"1";
			}
			else cout<<"0";
		}
		else{
			cout<<"00";
		}
	}
	else cout<<"000";
}
fclose(stdin);
fclose(stdout);
return 0;	
}
