#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int n1,n2,n3,n4;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c1>>s1>>c2>>s2;
	n1=(c1[0]-'0')*10+c1[1]-'0';
	n2=(c2[0]-'0')*10+c2[1]-'0';
	n3=(s1[0]-'0')*10+s1[1]-'0';
	n4=(s2[0]-'0')*10+s2[1]-'0';
	char a=s1[2],b=s2[2];
	if(n1!=n2) {cout<<"0000"; return 0;}
	if(n3!=n4) {cout<<"1000"; return 0;}
	if((a>='D' && b<='C') || (a<='C' && b>='D')) {cout<<"1100"; return 0;}
	if(abs(int(a-b))!=1 && !(a=='D' && b=='F') && !(a=='F' && b=='D')) {cout<<"1110"; return 0;}
	cout<<"1111";
	return 0;
}
