#include<bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;
int main()
{
	freopen("travel.in","r",stdin); 
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		cout<<1;
	    int n1=int(s1[0])*10+int(s1[1]);
	    int n2=int(s2[0])*10+int(s2[1]);
	    if(n1==n2)
	    {
		    cout<<1;
		    int m1,m2;
	        if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C')
 	        {
		        m1=1;
	        }
	        if(s1[2]=='D'||s1[2]=='F')
	        {
		        m1=0;
	        }
	        if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C')
	        {
	 	        m2=1;
	        }
	        if(s2[2]=='D'||s2[2]=='F')
	        {
		        m2=0;
	        }
	        if(m1==m2)
	        {
		        cout<<1;
		        int j1=0,j2=0;
		        if(m1==1)
	            {
	    	        if(s1[2]=='A')
	    	        {
	    		        j1=1;
	    		        if(s2[2]=='B')
	    		        {
	    			        j2=2;
				        }
				        if(s2[2]=='C')
				        {
					        j2=3;
				        }
		            }
			        if(s1[2]=='B')
			        {
				        j1=2;
				        if(s2[2]=='A')
				        {
					        j2=1;
				        }
				        if(s2[2]=='C')
				        {
					       j2=3;
				        }
			        }
			        if(s1[2]=='C')
		 	        {
				        j1=3;
				        if(s2[2]=='A')
				        {
				  	        j2=1;
				        }
				        if(s2[2]=='B')
				        {
					        j2=2;
				        }
			        }
			    }	
		        if(m1==0)
		        {
			        j1=4;
			        j2=5;
		        }
		        int e=j1+j2;
		        if(e==3||e==5||e==9)
		        {
			        cout<<1;
			        
		        }
		        else
		        {
			        cout<<"0";
		        }
 	        }
 	        else
 	        {
 	        	cout<<"00";
			}
 	    }
	    else
	    {
		    cout<<"000";
	    }
    }
	else
	{
		cout<<"0000";
	}
	 
	return 0;
}
