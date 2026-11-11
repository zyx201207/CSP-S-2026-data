#include<bits/stdc++.h>
using namespace std;
bool x(char p,char q)
{
	if((p=='A'||p=='B'||p=='C')&&(q=='A'||q=='B'||q=='C')) return true;
	else if((p=='D'||p=='F')&&(q=='D'||q=='F')) return true;
	else return false;
}
bool y(char p,char q)
{
	if(p=='D'||q=='D') return true;
	else if(abs(p-q)==1) return true;
	else return false;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	string a1=s1.substr(0,2);
	string a2=s2.substr(0,2);
	
	if(c1==c2)
	{
		cout<<"1";
		if(a1==a2)
		{
			cout<<"1";
			if(x(s1[2],s2[2])) 
			{
				cout<<"1";
				if(y(s1[2],s2[2])) cout<<"1";
				else cout<<"0";
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
} 
