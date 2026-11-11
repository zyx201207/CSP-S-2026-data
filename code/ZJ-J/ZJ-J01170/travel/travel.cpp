#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){cout<<"0000";return 0;}
	int h1=(s1[0]-'0')*10+s1[1]-'0',h2=(s2[0]-'0')*10+s2[1]-'0';
	if(h1!=h2){cout<<"1000";return 0;}
	int side1=2,side2=2;
	if(s1[2]<='C')side1=1;
	if(s2[2]<='C')side2=1;
	if(side1!=side2){cout<<"1100";return 0;}
	int l1=s1[2]-'A',l2=s2[2]-'A';
	if(abs(l1-l2)!=1){cout<<"1110";return 0;}
	cout<<"1111";
	return 0;
}
