#include<bits/stdc++.h>
using namespace std;
char a1[3],a2[3],b1[3],b2[3];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    cin>>a1>>a2>>b1>>b2;
    if(a1[0]==b1[0]&&a1[1]==b1[1]){
    	cout<<1;
	}
	else{
		cout<<0;
	}
	if(a2[0]==b2[0]&&a2[1]==b2[1]){
    	cout<<1;
	}
	else{
		cout<<0;
	}
	if(a2[0]==b2[0]&&a2[1]==b2[1]&&((a2[2]>='A'&&a2[2]<='C'&&b2[2]>='A'&&b2[2]<='C')||(a2[2]>='D'&&a2[2]<='F'&&b2[2]>='D'&&b2[2]<='F'))){
    	cout<<1;
	}
	else{
		cout<<0;
	}
	if(a2[0]==b2[0]&&a2[1]==b2[1]&&((a2[2]>='A'&&a2[2]<='C'&&b2[2]>='A'&&b2[2]<='C')||(a2[2]>='D'&&a2[2]<='F'&&b2[2]>='D'&&b2[2]<='F'))&&((a2[2]=='D'&&b2[2]=='F')||(a2[2]=='F'&&b2[2]=='D')||(a2[2]=='A'&&b2[2]=='B')||(a2[2]=='B'&&b2[2]=='A')||(a2[2]=='B'&&b2[2]=='C')||(a2[2]=='C'&&b2[2]=='B'))){
    	cout<<1;
	}
	else{
		cout<<0;
	}
	return 0;
}
