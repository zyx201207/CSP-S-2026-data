#include<iostream>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string co;
    string ct;	
	int so=0,st=0;
	cin>>so>>co>>st>>ct;
	if(so==st) cout<<"1";
	else {
	cout<<"0000";
	return 0;}
    if(co[0]==ct[0]&&co[1]==ct[1]) cout<<"1";
    else {
	cout<<"000";//qian2
    return 0;}
    if((co[2]=='A')||(co[2]=='B')||(co[2]=='C')&&(ct[2]=='A')||(ct[2]=='B')||(ct[2]=='C'))
	
    cout<<"1";
    else if(co[2]=='D'||co[2]=='F'&&ct[2]=='D'||ct[2]=='F')
        cout<<"1";
    else {
	cout<<"00";
	return 0;}
    if(co[2]=='A'&&ct[2]=='B') cout<<"1";
    else if(co[2]=='B'&&ct[2]=='A'||ct[2]=='C') cout<<"1";
    else  if(co[2]=='C'&&ct[2]=='B') cout<<"1";
    else  if(co[2]=='D'&&ct[2]=='E') cout<<"1";
    else  if(co[2]=='E'&&ct[2]=='D') cout<<"1";
    else cout<<"0";
	return 0;
}