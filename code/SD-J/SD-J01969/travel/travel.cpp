#include<bits/stdc++.h>
using namespace std;
int main() 
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	string s1,s2,h1,h2;
	cin>>s1>>h1>>s2>>h2;
	if(s1==s2)cout<<'1';
	else cout<<'0';
	if(s1==s2&&h1[0]==h2[0]&&h1[1]==h2[1])cout<<'1';
	else cout<<'0';
	if(s1==s2&&h1[0]==h2[0]&&h1[1]==h2[1]&&(h1[2]-'A'<=2&&h2[2]-'A'<=2)||(h1[2]-'A'>=3&&h2[2]-'A'>=3&&h1[2]-'A'<=5&&h2[2]-'A'<=5))cout<<'1';
	else cout<<'0';
	if(s1==s2&&h1[0]==h2[0]&&h1[1]==h2[1]&&((h1[2]-'A'<=2&&h2[2]-'A'<=2)||(h1[2]-'A'>=3&&h2[2]-'A'>=3&&h1[2]-'A'<=5&&h2[2]-'A'<=5))&&abs(h1[2]-h2[2])==1)cout<<'1';
	else cout<<'0';
	return 0;
}
