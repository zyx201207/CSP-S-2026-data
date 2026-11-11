#include <bits/stdc++.h>
using namespace std;
int jueduizhi(char a,char b)
{
	if(a-b>=0) 
	{
		return a-b;
	}
	else
	{
		return b-a;
	}
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,A,B;
	cin>>a>>b>>A>>B;
	if(a==A)
	{
		cout<<"1";
		if(b[0]==B[0]&&b[1]==B[1])
	    {
	    	cout<<"1";
	    	if(b[2]>='D'&&B[2]>='D'||b[2]<'D'&&B[2]<'D')
	    	{
	    		cout<<"1";
	    		if(jueduizhi(b[2],B[2])==1&&((b[2]!='D'&&B[2]!='C')||(b[2]!='C'&&B[2]!='D')))
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
	else
	{
		cout<<"0000";
		return 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
