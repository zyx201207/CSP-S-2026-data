#include<bits/stdc++.h>
using namespace std;
string cc1,ss1,cc2,ss2;
int main()
{	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>cc1>>ss1>>cc2>>ss2;
	if(cc1!=cc2)
	{	cout<<"0000";
		return 0;
	}
	if(ss1[0]!=ss2[0] || ss1[1]!=ss2[1])
	{	cout<<"1000";
		return 0;
	}
	if((ss1[2]<='C')!=(ss2[2]<='C'))
	{	cout<<"1100";
		return 0;
	}
	if(abs(ss1[2]-ss2[2])>1)
	{	cout<<"1110";
		return 0;
	}
	cout<<"1111";
	return 0;
}
