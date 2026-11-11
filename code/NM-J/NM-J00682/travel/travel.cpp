#include<bits/stdc++.h>
using namespace std;
string zy1,zy2,xy1,xy2;
int fd(char a)
 {
 	if(a=='A'||a=='B'||a=='C') return 0;
 	else return 1;
 }
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>zy1>>zy2>>xy1>>xy2;
	if(zy1==xy1)
	  {
	   	cout<<"1";
	   	if(zy2[0]==xy2[0]&&zy2[1]==xy2[1])
	   	          {
	   	          	 cout<<"1";
	   	       	     if(fd(xy2[2])==fd(zy2[2]))
	   	       	               {
	   	       	               	cout<<"1";
								if(abs(xy2[2]-zy2[2])==1)
								   cout<<"1";
								else cout<<"0";
							   }  
	   	       	      else cout<<"00";   
				  }
		  else 
		     	 cout<<"000";
	   }
	else cout<<"0000";  
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 
