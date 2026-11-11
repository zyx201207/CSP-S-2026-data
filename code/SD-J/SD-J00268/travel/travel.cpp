#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	int cr=(c1[0]-'0')*10+(c1[1]-'0'),cx=(c2[0]-'0')*10+(c2[1]-'0');
	int zr=(s1[0]-'0')*10+(s1[1]-'0'),zx=(s2[0]-'0')*10+(s2[1]-'0');
	char r=s1[2],x=s2[2];
	if(cr==cx){
		cout<<1;
		if(zr==zx){
			cout<<1;
			if(r>='A'&&r<='C'&&x>='A'&&x<='C'){
				cout<<1;
				if(abs(r-x)==1){
					cout<<1;
				}else{
					cout<<"0";
				}
			}else if(r>='D'&&r<='F'&&x>='D'&&x<='F'){
				cout<<"11";
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
