#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,s1,s2;
	cin>>c1>>c2>>s1>>s2;
	if(c1==s1){
		cout<<'1';
		int h1=(c2[0]-'0')*10+(c2[1]-'0');
		int h2=(s2[0]-'0')*10+(s2[1]-'0');
		if(h1==h2){
			cout<<'1';
			char a=c2[2],b=s2[2];
			if((a<='C'&&b<='C')||(a>='D'&&b>='D')){
				cout<<'1';
				if(a+1==b||b+1==a){
					cout<<'1';
				}else{
					cout<<"0";
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
