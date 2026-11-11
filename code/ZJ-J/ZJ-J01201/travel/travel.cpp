#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	
	if(c1==c2) // 1
	{
		cout<<1;
		if(s1[0]==s2[0] && s1[1]==s2[1])// 2
		{
			cout<<1;
			if((s1[2]<='C' && s2[2]<='C') || (s1[2]>='D' && s1[2]>='D'))// 3
			{
				cout<<1;
				if(abs(s1[2]-s2[2])==1)// 4
				{
					cout<<1;
				}
				else cout<<"0\n";
			}
			else cout<<"00\n";
		}
		else cout<<"000\n";
	}
	else cout<<"0000\n";
	
	return 0;
}
