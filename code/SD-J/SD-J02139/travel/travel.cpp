#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
char z1,z2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	z1=s1[2],z2=s2[2];
	if (c1!=c2){
		cout << "0000";
		return 0;
	}
	else
		cout << 1;
	if (s1[0]==s2[0] && s1[1]==s2[1])
		cout << 1;
	else{
		cout << "000";
		return 0;
	}
	if ((z1>='A'&&z1<='C'&&z2>='A'&&z2<='C')||(z1>='D'&&z1<='F'&&z2>='D'&&z2<='F'))
		cout<<1;
	else{
		cout<<"00";
		return 0;
	}
	if (z1>='A'&&z1<='C'&&z2>='A'&&z2<='C'){
		if (z1+1==z2 || z2+1==z1)
			cout << 1;
		else
			cout << 0;
	}
	if (z1>='D'&&z1<='F'&&z2>='D'&&z2<='F')
		cout << 1;
	return 0;
} 
