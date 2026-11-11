#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	int rc=(c1[0]-'0')*10+(c1[1]-'0');
	int xc=(c2[0]-'0')*10+(c2[1]-'0');
	if(rc==xc){
		cout<<"1";
		int rz=(s1[0]-'0')*10+(s1[1]-'0');
		int xz=(s2[0]-'0')*10+(s2[1]-'0');
		if(rz==xz){
			cout<<"1";
			char r=s1[2],x=s2[2];
			if((r>='A'&&r<='C'&&x>='A'&&x<='C')||(r>='D'&&r<='F'&&x>='D'&&x<='F')){
				cout<<"1";
				if(r+1==x||x+1==r){
					cout<<"1";
				}else{
					if((r=='D' && x=='F')||(r=='F'&&x=='D')){
						cout<<"1";
					}else{
						cout<<"0";
					}
				}
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
} 