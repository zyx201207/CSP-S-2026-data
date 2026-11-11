#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char cr[2],sr[3],cx[2],sx[3];
	cin>>cr[0]>>cr[1];
	cin>>sr[0]>>sr[1]>>sr[2];
	cin>>cx[0]>>cx[1];
	cin>>sx[0]>>sx[1]>>sx[2];
	bool a=0,b=0,c=0,d=0;
	if(cr[0]==cx[0]&&cr[1]==cx[1])a=1;
	if(a==1&&sr[0]==sx[0]&&sr[1]==sx[1])b=1;
	if(b==1&&((sr[2]>='D'&&sx[2]>='D')||(sr[2]<='C'&&sx[2]<='C')))c=1;
	if(c==1&&((sr[2]==sx[2]-1&&sx[2]!='D')||(sr[2]==sx[2]+1&&sx[2]!='C')))d=1;
	cout<<a<<b<<c<<d;
	return 0;
}
