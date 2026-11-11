#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(stoll(c1)==stoll(c2)) cout<<"1";
	else{
		cout<<"0000";
		return 0;
	}
	if(stoll(s1.substr(0,2))==stoll(s2.substr(0,2))) cout<<"1";
	else{
		cout<<"000";
		return 0;
	}
	char sc1=s1[2],sc2=s2[2];
	if((sc1<='C'&&sc2<='C')||(sc1>='D'&&sc2>='D')) cout<<"1";
	else{
		cout<<"00";
		return 0;
	}
	if(sc1+1==sc2||sc1-1==sc2) cout<<"1";
	else cout<<"0";
	return 0;
}