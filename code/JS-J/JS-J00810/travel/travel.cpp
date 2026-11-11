#include<bits/stdc++.h>
using namespace std;
string cc1,ss1,cc2,ss2;
bool check(){
	bool rr1,rr2;
	if(ss1[2]=='D')rr1=1;
	else if(ss1[2]=='F')rr1=1;
	else rr1=0;
	if(ss2[2]=='D')rr2=1;
	else if(ss2[2]=='F')rr2=1;
	else rr1=0;
	return rr1==rr2;
}
bool checkk(){
	if(ss1[2]=='A'&&ss2[2]=='B')return 1;
	if(ss1[2]=='B'&&ss2[2]=='A')return 1;
	if(ss1[2]=='C'&&ss2[2]=='D')return 1;
	if(ss1[2]=='D'&&ss2[2]=='C')return 1;
	if(ss1[2]=='D'&&ss2[2]=='F')return 1;
	if(ss1[2]=='F'&&ss2[2]=='D')return 1;
	return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>cc1>>ss1>>cc2>>ss2;
	if(cc1[0]==cc2[0]&&cc1[1]==cc2[1]){
		cout<<1;
	}
	else{
		cout<<"0000";
		return 0;
	}
	if(ss1[0]==ss2[0]&&ss1[1]==ss2[1]){
		cout<<1;
	}
	else{
		cout<<"000";
		return 0;
	}
	if(check()){
		cout<<1;
	}
	else{
		cout<<"00";
		return 0;
	}
	if(checkk()){
		cout<<1;
	}
	else{
		cout<<"0";
		return 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
