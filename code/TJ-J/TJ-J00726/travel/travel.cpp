#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	bool aaa,bbb,ccc;
	for(int i=0;i<2;i++)
	{
		if(c1[i]!=c2[i])
		aaa=false;
		else aaa=true;
	}
	if(aaa==false) cout<<"0000";
	else cout<<1;
	if(aaa==true)
	{
		for(int i=0;i<2;i++)
	    {
		    if(s1[i]!=s2[i])
		    bbb=false;
		}
		if(bbb==false) cout<<"000";
        else
		{
		    bbb=true;	
		    cout<<1;
	    }
    }
	if(bbb==true)
	{
		if((s1[2]=='A'&&s2[2]=='B'||s2[2]=='C')||(s1[2]=='B'&&s2[2]=='A'||s2[2]=='C')||(s1[2]=='C'&&s2[2]=='A'||s2[2]=='B')||(s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D'))
	    {
	    	cout<<1;
	    	ccc=true;
		}
		else
		{
			ccc=false;
			cout<<"00";
		}
	}
	if(ccc==true)	
	{
		if((s1[2]=='B')||(s2[2]=='B')||(s1[2]=='D')||(s1[2]=='F'))
		cout<<1;
		else cout<<0; 
	}
	return 0;
}
