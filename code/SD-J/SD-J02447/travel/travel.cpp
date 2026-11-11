#include<iostream>
using namespace std;
int a,b,a1,a2;
string s1,s2;
int ans;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>s1>>b>>s2;
    //cout<<s1[0]<<s1[1]<<s2[0]<<s2[1]<<'\n';
    //cout<<a<<b<<' ';
    if(a!=b)
    {
    	cout<<"0000";
    	return 0;
	}
    if(a==b) 
    {
    	if(s1[0]==s2[0]&&s1[1]==s2[1])
   		{
    		if((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='A')||(s1[2]=='A'&&s2[2]=='C')||(s1[2]=='C'&&s2[2]=='A')||(s1[2]=='C'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='C')||(s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D'))
    		{
    			if((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='A')||(s1[2]=='C'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='C')||(s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D')){
					cout<<1111;
					return 0;
				}
				else{
					cout<<1110;
					return 0;
				}
			}
			else{
				cout<<1100;
				return 0;
			}
		}
		else{
			cout<<1000;
			return 0;
		}
	}	
	return 0;
}

