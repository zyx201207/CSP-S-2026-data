#include<bits/stdc++.h>
using namespace std;
int k1,k2;
char aa,bb;
string a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	aa=b[2],bb=d[2];
	k1+=(int(b[0])-48)*10+(int(b[1])-48);
	k2+=(int(d[0])-48)*10+(int(d[1])-48);
	if(a==c){
		cout<<"1";
		if(k1==k2){
			cout<<"1";
			if((aa=='D'&&bb=='F')||(aa=='F'&&bb=='D')){
				cout<<"11";
				return 0;
			}
			else if((aa=='A'&&bb=='B')||(aa=='B'&&bb=='C')||(aa=='B'&&bb=='A')||(aa=='C'&&bb=='B')){
				cout<<"11";
				return 0;
			}
			else if((aa=='A'&&bb=='C')||(aa=='C'&&bb=='A')){
				cout<<"10";
			}
			else{
				cout<<"00";
				return 0;
			}
		}
		else{
			cout<<"000";
			return 0;
		}
	}
	else{
		cout<<"0000";
		return 0;
	}
	return 0;
}
