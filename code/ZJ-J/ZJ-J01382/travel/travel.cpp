#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b,fa=2,fb=2;
	string sa,sb;
	cin>>a>>sa>>b>>sb;
	if(sa[2]=='A'||sa[2]=='B'||sa[2]=='C')fa=1;
	if(sb[2]=='A'||sb[2]=='B'||sb[2]=='C')fb=1;
	if(a!=b)cout<<"0000";
	else if(sa[0]!=sb[0]||sa[1]!=sb[1])cout<<"1000";
	else if(fa!=fb)cout<<"1100";
	else if(abs(sa[2]-sb[2])!=1)cout<<"1110";
	else cout<<"1111";
	return 0;
}