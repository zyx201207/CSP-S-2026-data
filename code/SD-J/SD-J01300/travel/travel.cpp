#include <bits/stdc++.h>
using namespace std;
using ll=long long;
string c1,s1,c2,s2;
bool pc(){
	int a,b;
	a=(s1[2]>='A'&&s1[2]<='C');
	b=(s2[2]>='A'&&s2[2]<='C');
	return (a==b);
}
bool xl(){
	if(!pc()) return 0;
	if(s1[2]=='F') s1[2]--;
	if(s2[2]=='F') s2[2]--;
	int a=s1[2]-'A';
	int b=s2[2]-'A';
	return (abs(a-b)==1);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	cout<<(c1==c2);
	cout<<((c1==c2)&&(s1[0]==s2[0]&&s1[1]==s2[1]));
	cout<<((c1==c2)&&(s1[0]==s2[0]&&s1[1]==s2[1])&&pc());
	cout<<((c1==c2)&&(s1[0]==s2[0]&&s1[1]==s2[1])&&xl());
	return 0;
}
