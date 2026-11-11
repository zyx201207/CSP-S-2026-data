#include<bits/stdc++.h>
using namespace std;
int flrn,flrm,flxn,flxm;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char rn[10],rm[10];
	char xn[10],xm[10]; 
	cin>>rn[1]>>rn[2];
	cin>>rm[1]>>rm[2]>>rm[3];
	cin>>xn[1]>>xn[2];
	cin>>xm[1]>>xm[2]>>xm[3];
	flrn=10*(rn[1]-'0')+(rn[2]-'0');
	flxn=10*(xn[1]-'0')+(xn[2]-'0');
    flrm=10*(rm[1]-'0')+(rm[2]-'0');
	flxm=10*(xm[1]-'0')+(xm[2]-'0');
	if(flrn==flxn)
	{
		cout<<"1";
		    if(flrm==flxm)
	        {
		    cout<<"1";
		        if((rm[3]=='C'&&xm[3]=='D')||(rm[3]=='D'&&xm[3]=='C'))
	            {
		            cout<<"0"<<"0";
	            }
	        else 
	        {
		        cout<<"1";
		        if((rm[3]-xm[3]==1||xm[3]-rm[3]==1)||(rm[3]=='D'&&xm[3]=='F')||(rm[3]=='F'&&xm[3]=='D'))
	            {
		            cout<<"1";
	            }
	            else
	            {
		            cout<<"0";
	            }
	        }
	        }
	        else
	        {
		    cout<<"0"<<"0"<<"0";
	        }
    }
	else
	{
		cout<<"0"<<"0"<<"0"<<"0";
	}
	
	
	
	
	return 0;
} 
