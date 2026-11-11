#include<bits/stdc++.h>
using namespace std;
int ca,cb,f=1;
char sa[5],sb[5];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>ca;
	for(int i=1;i<=3;i++){
		cin>>sa[i];
	}
	cin>>cb;
	for(int i=1;i<=3;i++){
		cin>>sb[i];
	}
	if(ca==cb){
		cout<<"1";
		if(sa[1]==sb[1]&&sa[2]==sb[2]){
			cout<<1;
			if(sa[3]<='C'&&sb[3]<='C'||sa[3]>'C'&&sb[3]>'C'){
				cout<<1;
				if(sa[3]=='A'&&sb[3]=='B'){
					cout<<1;
				}else if(sa[3]=='B'&&sb[3]=='C'){
					cout<<1;
				}else if(sa[3]=='D'&&sb[3]=='F'){
					cout<<1;
				}else{
					cout<<0;
					return 0;
				}
			}else{
				cout<<"00";
				return 0;
			}
		}else{
			cout<<"000";
			return 0;
		}
	}else{
		cout<<"0000";
		return 0;
	}
	return 0;
}