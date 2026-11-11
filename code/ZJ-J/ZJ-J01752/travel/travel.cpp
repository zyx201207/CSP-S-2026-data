#include<bits/stdc++.h>
using namespace std;
string a1,a2,b1,b2;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>a2>>b1>>b2;
	if(a1!=b1) cout<<"0000";
	else if(a2.substr(0,2)!=b2.substr(0,2)) cout<<"1000";
	else if((a2[2]<='C'&&b2[2]>'C')||(a2[2]>'C'&&b2[2]<='C')) cout<<"1100";
	else if(abs(a2[2]-b2[2])>1) cout<<"1110";
	else cout<<"1111";
}
