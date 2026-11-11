#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a1,b1,flag=0;//³µÏá 
	string a2,b2;//×ùÎ» 
	cin>>a1>>a2>>b1>>b2;
	if(a1!=b1){
		flag=1;
	}else{
		if(a2[0]==b2[0]&&a2[1]==b2[1]){
			if(a2[2]=='A'||a2[2]=='B'||a2[2]=='C'){
				if(b2[2]=='A'||b2[2]=='B'||b2[2]=='C'){
					if(a2[2]=='A'||a2[2]=='C'){
						if(b2[2]!='B')flag=4;
					}
				}else{
					flag=3;
				}
			}else{
					if(b2[2]=='D'||b2[2]=='F'){	
					}else flag=3;
				}
		}else{
			flag=2;
		}
	}
	if(flag==0){
		cout<<"1111";
	}
	else if(flag==1)cout<<"0000";
	else if(flag==2)cout<<"1000";
	else if(flag==3)cout<<"1100";
	else cout<<"1110";
	return 0;
}
