#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<"1";
			bool side1=(s1[2]>='A'&&s1[2]<='C');
			bool side2=(s2[2]>='A'&&s2[2]<='C');
			if(side1==side2){
				cout<<"1";
				int si1=s1[2]-'A';
				int si2=s2[2]-'A';
				if(si1==5){
					--si1;
				}
				if(si2==5){
					--si2;
				}
				if(si1-si2==1||si1-si2==-1){
					cout<<"1";
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
