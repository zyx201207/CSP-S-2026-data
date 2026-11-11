#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string xi1,sit1;
	string xi2,sit2;
	cin>>xi1>>sit1>>xi2>>sit2;
	if(xi1==xi2)
	{
		cout<<"1";
		if(sit1[1]==sit2[1]&&sit1[0]==sit2[0])
		{
			cout<<"1";
			if((sit1[2]<='C'&&sit2[2]<='C')||(sit1[2]>='D'&&sit2[2]>='D'))
			{
				cout<<"1";
				if(sit1[2]-1==sit2[2]||sit1[2]+1==sit2[2])
				{
					cout<<"1";
				}
				else
				{
					cout<<"0";
					return 0;
				}
			}
			else
			{
				cout<<"00";
				return 0;
			}
		}
		else
		{
			cout<<"000";
			return 0;
		}
	}
	else{
		cout<<"0000";
		return 0;
	}
	return 0;
}
