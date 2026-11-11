#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2,c1,c2;
	cin>>s1>>s2>>c1>>c2;
	if(s1!=c1){
		cout<<"0000";
		return 0;
	}
	else{
		cout<<"1";
		if(s2[0]==c2[0]&&s2[1]==c2[1]){
			cout<<"1";
			char s,c;
			s=s2[2];
			c=c2[2];
			if(s<='C'&&c<='C'){
				cout<<"1";
				if(abs(c-s)!=1){
					cout<<"0";
				}
				else{
					cout<<"1";
				}
			}
			else if(s>'C'&&s<'G'&&c>'C'&&c<'G'){
				cout<<"11";
				return 0;
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
	return 0;
}