#include<bits/stdc++.h>
using namespace std;
char a[13];
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
for(int i=0;i<10;i++)cin>>a[i];
int n1=(a[0]-'0')*10+(a[1]-'0');
int n2=(a[5]-'0')*10+(a[6]-'0');
int sn1=(a[2]-'0')*10+(a[3]-'0');
int sn2=(a[7]-'0')*10+(a[8]-'0');
char sc1=a[4];
char sc2=a[9];
if(n1==n2)cout<<1;
else
{cout<<"0000";
return 0;
}
if(sn1==sn2)cout<<1;
else{cout<<"000";
return 0;
}
if(sc1=='A'){
	if(sc2=='B')cout<<"11";
	else if(sc2=='C')cout<<"10";
	else if(sc2=='D')cout<<"00";
	else if(sc2=='F')cout<<"00";

}else if(sc1=='B'){
if(sc2=='A')cout<<11;
	else if(sc2=='C')cout<<"11";
	else if(sc2=='D')cout<<"00";
	else if(sc2=='F')cout<<"00";
}
else if(sc1=='C'){
if(sc2=='A')cout<<10;
	else if(sc2=='B')cout<<"11";
	else if(sc2=='D')cout<<"00";
	else if(sc2=='F')cout<<"00";
}
else if(sc1=='D'){
if(sc2=='A')cout<<"00";
	else if(sc2=='C')cout<<"00";
	else if(sc2=='B')cout<<"00";
	else if(sc2=='F')cout<<"11";
}
else if(sc1=='F'){
if(sc2=='A')cout<<"00";
	else if(sc2=='C')cout<<"00";
	else if(sc2=='D')cout<<"11";
	else if(sc2=='B')cout<<"00";
}
return 0;
}
