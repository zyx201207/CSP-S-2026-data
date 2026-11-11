#include <bits/stdc++.h>
using namespace std;
string r1,r2,x1,x2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>r1>>r2>>x1>>x2;
	if(r1!=x1||r1=="01"||r1=="16"||x1=="01"||x1=="16"){
		cout<<"0000"<<endl;
		return 0;
	}
	cout<<"1";
	if(r2[0]!=x2[0]||r2[1]!=x2[1]){
		cout<<"000"<<endl;
		return 0;
	}
	cout<<"1";
	int flag=0;
	if(r2[2]=='A'||r2[2]=='B'||r2[2]=='C'){
		if((x2[2]=='A'||x2[2]=='B'||x2[2]=='C')&&x2[2]!=r2[2]){
			cout<<"1";
		}else{
			flag=1;
		}
	}else if(r2[2]=='D'||r2[2]=='E'){
		if((x2[2]=='D'||x2[2]=='E')&&x2[2]!=r2[2]){
			cout<<"1";
		}else{
			flag=1;
		}
	}else{
		flag=1;
	}
	if(flag==1){
		cout<<"00"<<endl;
		return 0;
	}
	if(r2[2]=='A'||r2[2]=='B'||r2[2]=='C'){
		if(r2[2]=='A'||r2[2]=='C'){
			if(x2[2]!='B'){
				cout<<"0";
				return 0;
			}
		}else if(r2[2]=='B'){
			if(x2[2]!='C'&&x2[2]!='A'){
				cout<<"0";
				return 0;
			}
		}
	}else{
		if(r2[2]=='D'){
			if(x2[2]!='E'){
				cout<<"0";
				return 0;
			}
		}else if(r2[2]=='E'){
			if(x2[2]!='D'){
				cout<<"0";
				return 0;
			}
		}
	}
	cout<<"1"<<endl;
	return 0;
}