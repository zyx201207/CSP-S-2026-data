#include<bits/stdc++.h>
using namespace std;
int number1,number2;
int pai1,pai2;
int row1,row2;
bool judgebox(){
	if(number1==number2){
		return true; 
	}
	return false;
}
bool judgepai(){
	if(pai1==pai2){
		return true; 
	}
	return false;
}
bool judgesame(){
	if(row1==0||row1==1||row1==2){
		if(row2==0||row2==1||row2==2){
			return true;
		}
		else{
			return false;
		}
	}
	else{
		if(row2==0||row2==1||row2==2){
			return false;
		}
		else{
			return true;
		}
	}
}
bool judgenext(){
	if(judgepai()){
		if(row1==0||row1==1||row1==2){
			if(judgepai()&&((row1+1==row2&&row1!=2)||row1-1==row2)){
				return true;
			}	
		}
		else if(row1==3||row1==4){
			if(judgepai()&&((row1-1==row2&&row1!=3)||row1+1==row2)){
				return true;
			}	
		}
	}
	else if(!judgepai()){
		if(row1==row2&&(pai1+1==pai2||pai1-1==pai2)){
			return true;
		}
	}
	return false;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	number1=((int)c1[0]-'0')*10+(int)c1[1]-'0';
	number2=((int)c2[0]-'0')*10+(int)c2[1]-'0';
	pai1=((int)s1[0]-'0')*10+(int)s1[1]-'0';
	pai2=((int)s2[0]-'0')*10+(int)s2[1]-'0';
	row1=s1[2]-'A';
	row2=s2[2]-'A';
	if(judgebox()){
		cout<<"1";
		if(judgepai()){
			cout<<"1";
			if(judgesame()){
				cout<<"1";
			}
			else{
				cout<<"0";
			}
		}
		else{
			cout<<"00";
		}
		if(judgenext()){
			cout<<"1";
		}
		else cout<<"0";
	}
	else if(!judgebox()){
		cout<<"0000";
	}
	return 0;
} 
