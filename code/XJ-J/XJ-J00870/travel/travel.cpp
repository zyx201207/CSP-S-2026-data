#include<bits/stdc++.h>
using namespace std;
int x1,x2,p1,p2;
char z1,z2;
string s1,s2,s3,s4;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>s2>>s3>>s4;
	if(s1[0]=='0')
	{
		x1=s1[1]-'0';
    }else{
    	x1=(s1[0]-'0')*10+(s1[1]-'0');
	}  
	
	
	if(s3[0]=='0')
	{
		x2=s3[1]-'0';
    }else{
    	x2=(s3[0]-'0')*10+(s3[1]-'0');
	}
	
	
	if(s2[0]=='0')
	{
		p1=s2[1]-'0';
    }else{
    	p1=(s2[0]-'0')*10+(s2[1]-'0');
	}
	
	
	
	
	if(s4[0]=='0')
	{
		p2=s4[1]-'0';
    }else{
    	p2=(s4[0]-'0')*10+(s4[1]-'0');
	}
	
	
	
	z1=s2[2];
	z2=s4[2];
	
	if(x1==x2)
	{
		cout<<"1";
			if(p1==p2)
	        {
		    cout<<"1";
			    if(z1>='A'&&z1<='C'&&z2>='A'&&z2<='C')
	            {
		        cout<<"1";
	            	if(z1+1==z2||z2+1==z1)
	                {
		            cout<<"1";
		            }else{
		                cout<<"0";
                   	}
                }
				else if(z1=='D'&&z2=='F')
		        {
		        	cout<<"11";
				}else if(z1=='F'&&z2=='D')
				{
					cout<<"11";
				}
				else{
	        	cout<<"00";
	            }
	        }
	        else{
	        	cout<<"000";
			}
	}
	else{
		cout<<"0000";
	}
	return 0;





}