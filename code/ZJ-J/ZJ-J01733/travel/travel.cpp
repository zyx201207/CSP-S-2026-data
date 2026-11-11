#include<bits/stdc++.h>
using namespace std;

string c1,s1,c2,s2;
int C1,C2;
bool a,b,c,d,same_side,same_row;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	
	cin>>c1>>s1>>c2>>s2;
	for(int i=0;i<2;i++)
	{
		C1=C1*10+(c1[i]-'0');
		C2=C2*10+(c2[i]-'0');
	}
//	cout<<C1<<" "<<C2<<"\n";
	string row1=s1.substr(0,2);
	string row2=s2.substr(0,2);
//	cout<<row1<<" "<<row2<<"\n";
	same_side=(s1[2]<='C' && s2[2]<='C' || s1[2]>='D' && s1[2]<='F' && s2[2]>='D' && s2[2]<='F');
	same_row=(row1==row2);
	a=(C1==C2);
	b=(a && same_row);
	c=(a && b && same_side);
	d=(a && same_side && same_row && abs(s1[2]-s2[2])==1 );
	cout<<a<<b<<c<<d;
	return 0;
}
//02 01A 02 01B
//02 01C 02 01D
//02 02B 02 01A
//02 01A 03 01A