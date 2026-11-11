#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000"<<endl;
		return 0;
	}else{
		cout<<1;
	}
	//cout<<endl<<1<<endl;
	if(s1[0]!=s2[0]||s1[1]!=s2[1]){
		cout<<"000"<<endl;
		return 0; 
	}else{
		cout<<1; 
	}
	//cout<<endl<<2<<endl;
	if(((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='D'||s2[2]=='F'))||(
	(s1[2]=='D'||s1[2]=='F')&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'))){
		cout<<"00"<<endl;
		return 0;
	}else{
		cout<<1;
	}
	//cout<<endl<<3<<endl;
	if((s1[2]=='A'&&(s2[2]=='B'))
	||(s1[2]=='B'&&(s2[2]=='A'||s2[2]=='C'))
	||(s1[2]=='C'&&(s2[2]=='B'))
	||(s1[2]=='D'&&(s2[2]=='F'))
	||(s1[2]=='F'&&(s2[2]=='D'))){
		cout<<1<<endl; 
	}else{
		cout<<0<<endl;
	}
	//cout<<endl<<4<<endl;
	return 0;
}
