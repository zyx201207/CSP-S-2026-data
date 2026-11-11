#include<bits/stdc++.h>
using namespace std;

int hx,hr;
string wx,wr;

bool pd(char r,char x){
	if(r=='A'||r=='B'||r=='C'){
		if(x=='D'||x=='F'){
			cout<<"00";
			return 0;
		}else{
			cout<<1;
			return 1;
		}
	}else{
		if(x=='A'||x=='B'||x=='C'){
			cout<<"00";
			return 0;
		}else{
			cout<<1;
			return 1;
		}
	}
}

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin>>hr>>wr>>hx>>wx;
	if(hr==hx){
		cout<<1;
		if(wx[0]==wr[0]&&wx[1]==wr[1]){
			cout<<1;
			if(pd(wr[2],wx[2])){
				if((wr[2]+1)==wx[2]||(wr[2]-1)==wx[2]){
					cout<<1;
				}else{
					cout<<0;
				}
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
}
