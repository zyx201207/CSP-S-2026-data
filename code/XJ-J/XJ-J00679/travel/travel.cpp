#include <bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
bool f1,f2,f3,f4;
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)f1=true;
	if(f1&&s1[0]==s2[0]&&s1[1]==s2[1])f2=true;
	if(f1&&f2&&((s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C')||(s1[2]>='D'&&s1[2]<='F'&&s1[2]>='D'&&s1[2]<='F')))f3=true;
	if(f1&&f2&&f3&&s1[2]+1==s2[2])f4=true;
	cout<<f1<<f2<<f3<<f4;
	return 0;
}
