#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e3+10;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	bool b1=(c1==c2);
	bool b2=(((s1[0]-'0')*10+s1[1]-'0')==((s2[0]-'0')*10+s2[1]-'0'));
	bool b3=(s1[2]<='C' && s2[2]<='C' || s1[2]>'C' && s2[2]>'C');
	bool b4=(s1[2]+1==s2[2] || s1[2]-1==s2[2]);
	cout<<(b1)<<(b1&&b2)<<(b1&&b2&&b3)<<(b1&&b2&&b3&&b4);
	return 0;
}