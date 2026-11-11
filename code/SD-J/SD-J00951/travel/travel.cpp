#include<bits/stdc++.h>
using namespace std;
char c1,c2,s1[2],s2[2];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	
    if(c1==c2 && s1[1]==s2[1] && abs(int(s1[2])<=67&&int(s2[2])<=67&&abs(s1[2]-s2[2]==1) || int(s1[2])>67&&int(s2[2])>67))cout<<1111;
    
	if(int(c1)==int(c2))cout<<1;
	else
	{
		cout<<"0000";
		return 0;
	} 
	
	if(int(s1[1])==int(s2[1]))cout<<1;
    else
	{
		cout<<"000";
		return 0;
	} 
    
	if(int(s1[2])<=67&&int(s2[2])<=67 || int(s1[2])>67&&int(s2[2]>67))cout<<1;   
    else
	{
		cout<<"00";
		return 0;
	 } 
    
	if(int(s1[2])<=67&&int(s2[2])<=67&&abs(s1[2]-s2[2]==1) || int(s1[2])>67&&int(s2[2])>67)
      cout<<1;
    else cout<<0;
    
	return 0;
}
