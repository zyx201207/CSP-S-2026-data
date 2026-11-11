#include<bits/stdc++.h>
using namespace std;
int main()
{
//	int c1,c2,s1[5],s2[5];
//	for(int i=1;i<=2;i++)
//	{
//		cin>>c1[i];
//	}
//	for(int i=1;i<=3;i++)
//	{
//		cin>>s1[i];
//	}
//	for(int i=1;i<=2;i++)
//	{
//		cin>>c2[i];
//	}
//	for(int i=1;i<=3;i++)
//	{
//		cin>>s2[i]; 
//	}
//	if(c1[1]==c2[1] && c1[2]==c2[2]) 
//	{
//		cout<<1;
//		if(s1[1]==s2[1] && s1[2]==s2[2])
//	    {
//		    cout<<1;
//		    if(s1[3]<='C' && s2[3]<='C' || s1[3]>'C' && s2[3]>'C'  )
//		    {
//		    	cout<<1;
//		    	if(s2[3]-s1[3]==1 || s1[3]-s2[3]==1) cout<<1;
//			}
//			else cout<<0<<0;
//	    }
//	    else cout<<0<<0<<0;
//	}
//	else
//	{
//		cout<<0<<0<<0<<0;
//	}
//	
    
    int c1,c2,s1[5],s2[5];
    cin>>c1;
    for(int i=1;i<=3;i++)
    {
    	cin>>s1[i];
	}
	cin>>c2;
	for(int i=1;i<=3;i++)
	{
		cin>>s2[i];
	}
    if(c1==c2) 
    {
    	cout<<1;
//    	if(s1[1]==s2[1] &&  s1[2]==s2[2])
//    	{
//    		cout<<1;
//		}
//		else cout<<0<<0<<0;
	}
    else cout<<0<<0<<0<<0;
	return 0;
} 
