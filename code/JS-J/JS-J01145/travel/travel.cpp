#include <bits/stdc++.h>
using namespace std;
string a,b,c,d;
int c1,c2,s1,s2,sid1,sid2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	c1=(a[0]-'0')*10+a[1]-'0';
	c2=(c[0]-'0')*10+c[1]-'0';
	if (c1==c2)
	  cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	s1=(b[0]-'0')*10+b[1]-'0';
	s2=(d[0]-'0')*10+d[1]-'0';
	if (s1==s2)
	  cout<<1;
	else{
		cout<<"000";
		return 0;
	}
	sid1=(b[2]>='D');
	sid2=(d[2]>='D');
	if (sid1==sid2)
	  cout<<1;
	else{
		cout<<"00";
		return 0;
	}
	if (sid1)
	  cout<<1;
	else
	  cout<<(abs(b[2]-d[2])==1);
	return 0;
}
