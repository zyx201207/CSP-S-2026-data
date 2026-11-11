//李沐阳 SN-J00803 西安交通大学附属中学兴庆校区 初一年级
#include<bits/stdc++.h>
using namespace std;
int rc,xc;
string rs,xs;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>rc>>rs>>xc>>xs;
	if(rc==xc){
		cout<<"1";
		if((rs[0]==xs[0])&&(rs[1]==xs[1])){
			cout<<"1";
			char ra=rs[2],xa=xs[2];
			if(ra>'C'&&xa>'C')cout<<"11";
			else if(ra<='C'&&xa<='C')
				if((ra=='C'&&xa=='A')||(ra=='A'&&xa=='C'))cout<<"10";
				else cout<<"11";
			else cout<<"00";
			return 0;
		}else cout<<"000";
	}else cout<<"0000";
	return 0;
}
