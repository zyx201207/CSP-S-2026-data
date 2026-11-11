#include<bits/stdc++.h>

using namespace std;
struct cw
{
	string cx;
	string zw;
}r[2];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>r[0].cx>>r[0].zw>>r[1].cx>>r[1].zw;
	if(r[0].cx!=r[1].cx)
		cout<<"0000";
	else
		if(r[0].zw[0]!=r[1].zw[0]||r[0].zw[1]!=r[1].zw[1])
			cout<<"1000";
		else
			if(r[0].zw[2]>='A'&&r[0].zw[2]<='C')
				if(r[1].zw[2]>='A'&&r[1].zw[2]<='C')
					if(abs(r[1].zw[2]-r[0].zw[2])==1)
						cout<<"1111";
					else
						cout<<"1110";					
				else
					cout<<"1100";
			else
				if(r[1].zw[2]>='A'&&r[1].zw[2]<='C')
					cout<<"1100";
				else
					cout<<"1111";	
	return 0;
}
