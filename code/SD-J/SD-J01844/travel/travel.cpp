#include<bits/stdc++.h>
using namespace std;

string c1,s1,c2,s2,z1,z2;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin>>c1>>s1>>c2>>s2;
	
	z1=s1[0]+s1[1];
	z2=s2[0]+s2[1];
	
	cout<<(c1==c2);
	cout<<(z1==z2)*(c1==c2);
	cout<<((s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s2[2]>='D'))*(z1==z2)*(c1==c2);
	cout<<(s1[2]-1==s2[2]||s1[2]==s2[2]-1)*((s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s2[2]>='D'))*(z1==z2)*(c1==c2);
	
	return 0;
}
