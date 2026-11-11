#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int rc,rp,xc,xp;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	for(int i=0,k=10;i<c1.size();i++,k/=10){
		rc+=(c1[i]-'0')*k;
	}
	for(int i=0,k=10;i<c2.size();i++,k/=10){
		xc+=(c2[i]-'0')*k;
	}
	if(rc==xc){
		cout<<1;
	}else{
		cout<<"0000";
		return 0;
	}
	rp=(s1[0]-'0')*10+s1[1]-'0';
	xp=(s2[0]-'0')*10+s2[1]-'0';
	if(rp==xp){
		cout<<1;
	}else{
		cout<<"000";
		return 0;
	}
	char rz=s1[2],xz=s2[2];
	if(((rz=='A')&&((xz=='B')||(xz=='C')))||((rz=='B')&&((xz=='A')||(xz=='C')))||
	((rz=='C')&&((xz=='B')||(xz=='A')))||((rz=='D')&&(xz=='F'))||((rz=='F')&&(xz=='D'))){
		cout<<1;
	}else{
		cout<<"00";
		return 0;
	}
	if(((rz=='A')&&(xz=='B'))||((rz=='B')&&(xz=='C'))||((rz=='D')&&(xz=='F'))||
	((rz=='B')&&(xz=='A'))||((rz=='C')&&(xz=='B'))||((rz=='F')&&(xz=='D'))){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
