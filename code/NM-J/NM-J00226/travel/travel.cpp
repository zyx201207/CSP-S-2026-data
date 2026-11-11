#include<bits/stdc++.h>
using namespace std;
int main()
{
    string c1,c2,s1,s2;
    bool a,b;
    cin>>c1>>s1>>c2>>s2;
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    if(c1==c2)
    {
        cout<<"1";
        if(s1[1]==s2[1])
        {
            cout<<"1";
            while(1)
			{
				if('A'<=s1[2]<='C' && 'A'<=s2[2]<='C' )
            	{
            		if(s2[2]!='D')
            		{
            			cout<<"1";
            				if(s1[2]+1==s2[2] or s1[2]-1==s2[2])
                			{
                				if(s2[2]=='D' or s1[2]=='D')
                				{
                					cout<<"0";
                    				break;
								}
                    			else
               	    			{
               	    				cout<<"1";
                    				break;
							 	}
                			}
                			else
                			{
                    			cout<<"0";
                    			break;
                			}
					}	
            		else 
            		{
            			cout<<"0";
            				if(s1[2]+1==s2[2] or s1[2]-1==s2[2])
                			{
                				if(s1[2]=='C' or s2[2]=='C')
                				{
                					cout<<"0";
                    				break;
								}
                    			else
               	    			{
               	    				cout<<"1";
                    				break;
							 	}
                			}
                			else
                			{
                    			cout<<"0";
                    			break;
                			}
					}
            	}
            	if('D'<=s1[2]<='E' && 'D'<=s2[2]<='E' )
            	{
            		if(s2[2]!='C')
            		{
            			cout<<"1";
            				if(s1[2]+1==s2[2] or s1[2]-1==s2[2])
                			{
                				if(s1[2]=='C',s2[2]=='D' or s1[2]=='D',s2[2]=='C')
                				{
                					cout<<"0";
                    				break;
								}
                    			else
               	    			{
               	    				cout<<"1";
                    				break;
							 	}
                			}
                			else
                			{
                    			cout<<"0";
                    			break;
                			}
					}	
            		else 
            		{
            			cout<<"0";
            				if(s1[2]+1==s2[2] or s1[2]-1==s2[2])
                			{
                				if(s1[2]=='C',s2[2]=='D' or s1[2]=='D',s2[2]=='C')
                				{
                					cout<<"0";
                    				break;
								}
                    			else
               	    			{
               	    				cout<<"1";
                    				break;
							 	}
                			}
                			else
                			{
                    			cout<<"0";
                    			break;
                			}
					}
            	}
            	else 
				{
					cout<<"00";
					break;
				}
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
