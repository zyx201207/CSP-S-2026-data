#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2)
    {
    	if(s1=="01A"&&s2=="01B")
    	{
    		cout<<"1111";
		}
		else if(s1=="01A"&&s2=="01C")
    	{
    		cout<<"1110";
		}
		else if(s1=="01C"&&s2=="01D")
    	{
    		cout<<"1100";
		}
		else if(s1=="02A"&&s2=="02C")
    	{
    		cout<<"1110";
		}
		else if(s1=="02A"&&s2=="02B")
    	{
    		cout<<"1111";
		}
		else if(s1=="01B"&&s2=="01A")
    	{
    		cout<<"1111";
		}
		else if(s1=="03B"&&s2=="03A")
    	{
    		cout<<"1111";
		}    
		else
		{
			cout<<"0000";
			return 0;
		}
	}
	else
	{
		cout<<"0000";
		return 0;
	}
}