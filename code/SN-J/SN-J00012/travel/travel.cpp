#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2,p1,p2;
char ss1,ss2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	p1 = s1[0]+s1[1];
	p2 = s2[0]+s2[1];
	ss1 = s1[2];
	ss2 = s2[2];
	if (c1==c2){
		cout<<"1";
		if (p1==p2){
			cout<<"1";
			if (ss1<=67 && ss2<=67 || ss1>=68 && ss2>=68){
				cout<<"1";
				if (ss1+ss2!=132) cout<<"1";
				else cout<<"0";
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}

