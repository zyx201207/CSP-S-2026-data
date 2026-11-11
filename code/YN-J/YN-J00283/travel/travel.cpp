#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
string c1,s1;
string c2,s2;
int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000\n";
		return 0;
	}
	string t;
	string t1;
	t.clear();
	t1.clear();
	t+=s1[0];
	t+=s1[1];
	t1+=s2[0];
	t1+=s2[1];
	if(t!=t1){
		cout<<"1000\n";
		return 0;
	}
	if((s1[2]=='F'&&s2[2]!='D')||(s1[2]=='D'&&s2[2]!='F')||(s2[2]=='D'&&s1[2]!='F')||(s2[2]=='D'&&s1[2]!='F')){
		cout<<"1100\n";
		return 0;
	}
	if((s1[2]=='F'&&s2[2]=='D')||(s1[2]=='D'&&s2[2]=='F')){
		cout<<"1111\n";
		return 0;
	}
	if((s1[2]=='C'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='C')){
		cout<<"1111\n";
		return 0;
	}
	if((s1[2]=='B'&&s2[2]=='A')||(s1[2]=='A'&&s2[2]=='B')){
		cout<<"1111\n";
		return 0;
	}
	cout<<"1110\n";
	return 0;
}