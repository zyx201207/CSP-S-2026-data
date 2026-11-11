#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int sc1,sc2;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
		sc1=(s1[0]-'0')*10+(s1[1]-'0');
		sc2=(s2[0]-'0')*10+(s2[1]-'0');
		if(sc1==sc2){
			cout<<"1";
			char ss1=s1[2];
			char ss2=s2[2];
			if(ss1<='C'&&ss1>='A'&&ss2<='C'&&ss2>='A'){
				cout<<"1";
				if(abs(ss1-ss2)==1){
					cout<<"1";
				}else cout<<"0";
			}else if(ss1<='F'&&ss1>='D'&&ss2<='F'&&ss2>='D'){
				cout<<"11";
			}else cout<<"00";
		}else{
			cout<<"000";
		}
	}
	else{
		cout<<"0000";
	}
	
	return 0;
}
