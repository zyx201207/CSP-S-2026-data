//王宁远 西安辅轮中学 SN-J00726
#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a1,a2;
	string s1,s2;
	cin>>a1>>s1>>a2>>s2;
	if(a1!=a2) {
		cout<<"0000";
	} else if(s1[0]!=s2[0]||s1[1]!=s2[1]) {
		cout<<1000;
	} else if(((s1[2]>='D'&&s1[2]<='E')&&(s2[2]>='A'&&s2[2]<='C'))||((s2[2]>='D'&&s2[2]<='E')&&(s1[2]>='A'&&s1[2]<='C'))) {
		cout<<1100;
	} else if(abs(s1[2]-s2[2])!=1) {
		cout<<1110;
	} else {
		cout<<1111;

	}

}
