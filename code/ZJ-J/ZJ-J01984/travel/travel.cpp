#include<bits/stdc++.h>
using namespace std;
string cc1,ss1,cc2,ss2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> cc1 >> ss1 >> cc2 >> ss2;
	if(cc1 == cc2) cout<<"1";
	else cout<<"0";
	if(cc1 == cc2 && ss1[0] == ss2[0] && ss1[1] == ss2[1]) cout<<"1";
	else cout<<"0";
	if(cc1 == cc2 && ss1[0] == ss2[0] && ss1[1] == ss2[1] && ((ss1[2]-'A' <= 2 && ss2[2]-'A' <=2) || (ss1[2]-'A' > 2 && ss2[2]-'A' > 2))) cout<<"1";
	else cout<<"0";
	if(cc1 == cc2 && ss1[0] == ss2[0] && ss1[1] == ss2[1] && ((ss1[2]-'A' <= 2 && ss2[2]-'A' <=2) || (ss1[2]-'A' > 2 && ss2[2]-'A' > 2)) && (abs(ss1[2]-ss2[2]) == 1)) cout<<"1";
	else cout<<"0";
	return 0;
}
