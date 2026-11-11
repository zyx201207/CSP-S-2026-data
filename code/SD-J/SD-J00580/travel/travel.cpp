#include <bits/stdc++.h>
using namespace std;
string a,b,c,d,s="";
string t1,t2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout); 
	cin>>a>>b>>c>>d;
	if(a==c)
	{
		s+='1';
		t1=b[0]+b[1];
		t2=d[0]+d[1];
		if(t1==t2)
		{
			s+='1';
			if(b[2]>='A'&&b[2]<='C'&&d[2]>='A'&&d[2]<='C')
			{
				s+='1';
				if(b[2]==d[2]+1||b[2]==d[2]-1)
					s+='1';
				else{
					cout<<"1110";
					return 0;
				}
			}
			else if((b[2]=='D'||b[2]=='F')&&(d[2]=='D'||d[2]=='F'))
			{
				s+='1';
				if((b[2]=='D'&&d[2]=='F')||(b[2]=='F'&&d[2]=='D'))
					s+='1';
				else{
					cout<<"1110";
					return 0; 
				}
			}
			else{
				cout<<"1100";
				return 0;
			}
		}
		else{
			cout<<"1000";
			return 0;
		}
	}else{
		cout<<"0000";
		return 0;
	}
	cout<<s;
	return 0;
}
