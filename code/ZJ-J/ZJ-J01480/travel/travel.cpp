#include<bits/stdc++.h>
using namespace std;
#define int long long
string c1,c2,s1,s2;
int a,b;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	a=s1[2]-'A';b=s2[2]-'A';
	if(c1[0]!=c2[0]||c1[1]!=c2[1]) puts("0000");
	else if(s1[0]!=s2[0]||s1[1]!=s2[1]) puts("1000");
	else if((a<=2&&b>2)||(a>2&&b<=2)) puts("1100");
	else if(abs(a-b)!=1&&a<=2) puts("1110");
	else puts("1111");
	return 0;
}