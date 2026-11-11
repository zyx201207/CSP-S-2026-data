#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2,cnt=0,zxc=0,ui=0,op=0;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	char n=s1[2],m=s2[2];
	int a=n,s=m;
	if(s1[0]!=48){
        cnt=10;
	}
	if(s2[0]!=48){
        zxc=10;
	}
    int d=s1[1]-48+cnt,f=s2[1]-48+zxc;

    if(0<=a-s&&a-s<=1){
        ui=1;
    }
    if(0<=s-a&&s-a<=1){
        ui=1;
    }
    if(0<=d-f&&d-f<=1){
        op=1;
    }
    if(0<=f-d&&f-d<=1){
        op=1;
    }


	if(c1==c2){
		cout<<"1";
	}
	else{
		cout<<"0000";
		return 0;
	}
	if(d==f){
		cout<<"1";
	}
	else{
		cout<<"000";
		return 0;
	}
	if((a=='A'||a=='B'||a=='C')&&(s=='A'||s=='B'||s=='C')){
		cout<<"1";
	}
	else if((a=='D'||a=='E')&&(s=='D'||s=='E')){
		cout<<"1";
	}
	else{
		cout<<"00";
		return 0;
	}
	if(ui&&op){
        cout<<"1";
	}
	else{
		cout<<"0";
	}
	return 0;
}

