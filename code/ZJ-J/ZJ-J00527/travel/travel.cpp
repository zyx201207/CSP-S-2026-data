#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	a=(c1==c2);
	b=(a&&s1[0]==s2[0]&&s1[1]==s2[1]);
	if(b&&(s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s2[2]>='D'))c=true;
	else c=false;
	if(c&&(s1[2]-s2[2]==1||s2[2]-s1[2]==1))d=true;
	else d=false;
	cout<<a<<b<<c<<d;
	return 0;
}
