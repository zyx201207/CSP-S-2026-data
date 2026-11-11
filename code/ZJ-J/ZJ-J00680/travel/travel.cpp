#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
string a1,seat1,a2,seat2;
int g_line(){
	if((seat1[2]=='A'||seat1[2]=='B'||seat1[2]=='C')&&(seat2[2]=='A'||seat2[2]=='B'||seat2[2]=='C')){
		return 1;
	}
	if((seat1[2]=='D'||seat1[2]=='F')&&(seat2[2]=='D'||seat2[2]=='F')){
		return 1;
	}
	return 0;
}
int g_line2(){
	if(seat1[2]=='D'||seat2[2]=='D'){
		return 1;
	}
	if(!((seat1[2]=='A'&&seat2[2]=='C')||(seat2[2]=='A'&&seat1[2]=='C'))){
		return 1;
	}
	return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin>>a1>>seat1>>a2>>seat2;
	if(a1==a2){
		cout<<'1';
		if(seat1[0]==seat2[0]&&seat1[1]==seat2[1]){
			cout<<'1';
			if(g_line()==1){
				cout<<'1';
				if(g_line2()==1){
					cout<<'1';
					return 0;
				}
				else{
					cout<<"0";
					return 0;
				}
			}
			else{
				cout<<"00";
				return 0;
			}
		}
		else{
			cout<<"000";
			return 0;
		}
	}
	else{
		cout<<"0000";
		return 0;
	}
	fclose(stdin);
	fclose(stdout);
}