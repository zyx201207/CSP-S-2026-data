#include<bits/stdc++.h>
using namespace std;
//const int N=;
string c1,s1,c2,s2;
bool f=true;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2)
    {
    	cout<<"1";
    	for(int i=0;i<=1;i++)
    	{
    		if(s1[i]!=s2[i])
    		{
    			f=0;
			}
			
		}
		if(f)
		{
			cout<<"1";
		}
		else
		{
			cout<<"000";
			return 0;	
		}
		if((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='D'||s2[2]=='F'))
		{
			cout<<"00";
			return 0;
		}
		else if((s2[2]=='A'||s2[2]=='B'||s2[2]=='C')&&(s1[2]=='D'||s1[2]=='F'))
		{
			cout<<"00";
			return 0;	
		}
		else
		{
			cout<<"1";
		}
		if(abs(s1[2]-s2[2])==1)
		{
			cout<<"1";
		}
		else
		{
			cout<<"0";
		}
	}
	else
	{
		cout<<"0000";
	}
    return 0;
}

