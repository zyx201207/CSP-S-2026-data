#include<bits/stdc++.h>
using namespace std;
char c1t[3],c2t[3],s1t[4],s2t[4];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin>>c1t>>s1t>>c2t>>s2t;
	int c1,c2,s1,s2,x1,x2;
	c1=(c1t[0]-48)*10+(c1t[1]-48);
	c2=(c2t[0]-48)*10+(c2t[1]-48);
	s1=(s1t[0]-48)*10+(s1t[1]-48);
	s2=(s2t[0]-48)*10+(s2t[1]-48);
	x1=s1t[2]-64;
	x2=s2t[2]-64;
	//cout<<c1<<' '<<c2<<' '<<s1<<' '<<s2<<' '<<x1<<' '<<x2<<' ';
	if(c1==c2){
		cout<<1;
		if(s1==s2){
			cout<<1;
			if((x1<=3 && x2<=3) || (x1>3 && x2>3)){
				cout<<1;
				if(abs(x1-x2)==1) {
					cout<<1;
				}
				else {
					cout<<"0";
					return 0;
				}
			}
			else {
				cout<<"00";
				return 0;
			}
		}
		else {
			cout<<"000";
			return 0;
		}
	}
	else {
		cout<<"0000";
		return 0;
	}
	return 0;
}
