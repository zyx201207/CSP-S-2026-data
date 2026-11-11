#include<bits/stdc++.h>
using namespace std;
int a,b,c,d,s11,s22;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
    string c1,c2,s1,s2;
    cin>>c1>>s1>>c2>>s2;
    
    
    if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C') s11=1;
    
	if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C') s22=1;
	
	
    if(c1==c2)
    {
    	a=1; 
    	if(s1[0]==s2[0]&&s1[1]==s2[1])
    	{
	    	b=1;
	    	if(s11==s22)
	        {
	        	c=1;
	            if(s1[2]+1==s2[2]||s1[2]-1==s2[2])
                {
         	    	d=1;
            	}	
	        }
	    }
	}
	
	cout<<a<<b<<c<<d;
	
	return 0;
} 
