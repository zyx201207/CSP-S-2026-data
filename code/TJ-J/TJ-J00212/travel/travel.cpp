#include <bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >>a>>b>>c>>d;
	if (a!=c){
		cout <<"0000";
		return 0;
	}
	string s1 = b.substr(0,2);
	string s2=d.substr(0,2);
	if (s1!=s2){
		cout <<"1000";
		return 0;
	}
	char x = b[2],y=d[2];
	int n,m;
	if (x=='A'||x=='B'||x=='C')n=1;
	else if (x=='E'||x=='F')n=2;
	if (y=='A'||y=='B'||y=='C')m=1;
	else if (y=='E'||y=='F')m=2;
	if (n!=m){
		cout <<"1100";
		return 0;
	}
	if (x==y+1&&y!='C')cout <<"11111";
	else if (y==x+1&&x!='C')cout <<"1111";
	else cout <<"1110";
	return 0;
}
