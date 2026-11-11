#include<bits/stdc++.h>
#include<windows.h>
#include<fstream> 
using namespace std; 
int a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2,n="ABCDF";
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		a=1;
		if(s1[0]==s2[0]&&s1[1]==s2[1])
		{
			b=1;
			if(s1[2]<=n[2]&&s2[2]<=n[2]||s1[2]<=n[3]&&s2[2]<=n[4]||s1[2]<=n[4]&&s2[2]<=n[3])
			{
				c=1;
			}
		}
		if(s1[2]==n[0]&&s2[2]==n[1]||s1[2]==n[1]&&s2[2]==n[0]||s1[2]==n[1]&&s2[2]==n[2]||s1[2]==n[2]&&s2[2]==n[1]||s1[2]==n[4]&&s2[2]==n[3]||s1[2]==n[3]&&s2[2]==n[4])
			{
				d=1;
			}
	}
	cout<<a<<b<<c<<d;
	return 0;
 } 
