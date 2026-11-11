#include<bits/stdc++.h>
using namespace std;
string ss1,ss2,cc1,cc2;
bool pd[10];
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>cc1>>ss1>>cc2>>ss2;
    if(cc1==cc2)
    {
		cout<<"1";
		pd[2]=true;
	}
		    else
		    {
				cout<<"0";
			    pd[2]=false;
			}
    if((ss1[0]==ss2[0])&&(ss1[1]==ss2[1])&&(pd[2]==true))
    {
        cout<<"1";
	    pd[1]=true;
    }
                                                     else{
														     cout<<"0";
														     pd[1]=false;
														 }
    if(pd[1]==true)
    {           
	     if(ss1[2]=='A')
	     if((ss2[2]=='B')||(ss2[2]=='C')){
			                                  cout<<"1";
			                                  pd[3]=true;
			                             }
	     if(ss1[2]=='C')
	     if((ss2[2]=='A')||(ss2[2]=='B')){
			                                  cout<<"1";
			                                  pd[3]=true;
			                             }
	     if(ss1[2]=='D')
	     if(ss2[2]=='F'){
			                 cout<<"1";
			                 pd[3]=true;
			            }
	     if(ss1[2]=='F')
	     if(ss2[2]=='D'){
			                 cout<<"1";
			                 pd[3]=true;
			            }
	     if(pd[3]==false) cout<<"0";
    }                else cout<<"0";
    if(pd[1]==true)
    {
		if((ss1[2]=='A')&&(ss2[2]=='B')) 
		{
		    cout<<"1";
			pd[4]=true;
		}
		if((ss1[2]=='B')&&(ss2[2]=='A')) 
		{
		    cout<<"1";
			pd[4]=true;
		}
		if((ss1[2]=='B')&&(ss2[2]=='C')) 
		{
		    cout<<"1";
			pd[4]=true;
		}
		if((ss1[2]=='C')&&(ss2[2]=='B')) 
		{ 
		    cout<<"1"; 
			pd[4]=true;
		}
		if((ss1[2]=='D')&&(ss2[2]=='F'))
	    {
		    cout<<"1";
			pd[4]=true;
		}
		if((ss1[2]=='F')&&(ss2[2]=='D')) 
		{
		    cout<<"1";
			pd[4]=true;
		}
		if(pd[4]==false) cout<<"0";
    }
                else cout<<"0";
    fclose(stdin);
    fclose(stdout);
    return 0;
}
