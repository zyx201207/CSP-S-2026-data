#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	bool a=(c1==c2);
	bool b=(s1.substr(0,2)==s2.substr(0,2));
	// cout<<s1[2]<<' '<<s2[2];
	bool c=((s1[2]<='C' && s2[2]<='C') || (s1[2]>='D' && s2[2]>='D'));
	bool d= (abs(s1[2]-s2[2])==1) && ((s1[2]!='D' && s2[2]!='C') || (s1[2]!='C' && s2[2]!='D'));
	cout<<a;
	cout<<(a&&b);
	cout<< (a&&b&&c);

	cout<<(a&&b&&c&&d);
	return 0;
}
