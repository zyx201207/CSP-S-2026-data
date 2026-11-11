#include<bits/stdc++.h>
using namespace std;
string a1,a2,b1,b2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>a2>>b1>>b2;
	if(a1!=b1){cout<<"0000";return 0;}
	int p1=(int)(a2[0]-'0')*10+(int)(a2[1]-'0');
	int p2=(int)(b2[0]-'0')*10+(int)(b2[1]-'0');
	if(p1!=p2){cout<<"1000";return 0;}
	bool s1=('A'<=a2[2]&&'C'>=a2[2]);
	bool s2=('A'<=b2[2]&&'C'>=b2[2]);
	if(s1!=s2){cout<<"1100";return 0;}
	if((int)(a2[2]-b2[2])==1||(int)(b2[2]-a2[2])==1){cout<<"1111";return 0;}
	cout<<"1110";
	return 0;
}
