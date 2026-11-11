#include <iostream>
#include <cstdio> 
#include <math.h> 
using namespace std;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char s1[4],s2[4];
	int a1,a2;
	cin>>a1>>s1>>a2>>s2;
	int sa=(s1[0]-'0')*10+(s1[1]-'0'),st=(s2[0]-'0')*10+(s2[1]-'0');
	int a=s1[2]-'A'+1,b=s2[2]-'A'+1;
	bool t=(a1 == a2 ? 1 : 0);
	cout<<t<<" ";
	bool y=(sa == st && t? 1 : 0);
	cout<<y<<" ";
	bool l=( (a>=1 && a<=3 && b>=1 && b<=3 || a==4 && b==5 || a==5 && b==4 )&& t && y ? 1 : 0);
	cout<<l<<" ";
	cout<<(l && abs(a-b)==1 ? 1 : 0);
	return 0;
}
