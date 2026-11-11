#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	string t1,t2,c3,c4;
	cin>>c1>>c2>>c3>>c4;
	int a1=(t1[0]-'0'*10+t1[1]-'0');
	int a2=(t2[0]-'0'*10+t2[1]-'0');
	char ch=t1[2];
	char cd=t2[2];
	if(c1!=c2)
	{
		cout<<"0000";
		return 0;
		
	}
	else if(a1!=a2)
		{
			cout<<"1000";
		}
		else if(!((c1<='C' && c2<='C')|| c1>='D' && c2>='D'))
		{
			cout<<"1010";
		}
			else if(abs(c1-c2))
		{
			cout<<"1110";
		}
			else
		{
			cout<<"1111";
		}
	
	return 0;
}
