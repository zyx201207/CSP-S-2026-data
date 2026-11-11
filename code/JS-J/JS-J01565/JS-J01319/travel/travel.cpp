#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	bool a1,a2,a3,a4;
	a1=(c1==c2);
	a2=a1*(s1[0]==s2[0]&&s1[1]==s2[1]);
	a3=a2*(s1[2]>'C'&&s2[2]>'C'||s1[2]<'D'&&s2[2]<'D');
	a4=a3*(abs(s1[2]-s2[2])==1);
	cout<<a1<<a2<<a3<<a4;
	return 0;
}
