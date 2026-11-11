#include<bits/stdc++.h>
using namespace std;
string s1,s2;
int num1,num2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>num1>>s1>>num2>>s2;
	int w1,w2;
	char seat1,seat2;
	for(int i=0;i<3;i++){
		if(i==0){
			w1=s1[0]*10;
			w2=s2[0]*10;
		}
		if(i==1){
			w1+=s1[i];
			w2+=s2[i];
		}
		if(i==2){
			seat1=s1[i];
			seat2=s2[i];
		}
	}
	if(num1!=num2){
		cout<<"0000";
		return 0;
	}
	else{
		cout<<"1";
	}
	if(w1==w2){
		cout<<"1";
	}
	else{
		cout<<"000";
		return 0;
	}
	bool f1,f2;
	f1=(seat1>='A'&&seat1<='C'?true:false);
	f2=(seat2>='A'&&seat2<='C'?true:false);
	if(f1&&f2){
		cout<<"1";
	}
	else if(!f1&&f2){
		cout<<"1";
	}
	else{
		cout<<"00";
		return 0;
	}
	if(seat1-seat2==1){
		cout<<"1";
	}
	else if(seat2-seat1==1){
		cout<<"1";
	}
	else{
		cout<<0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
