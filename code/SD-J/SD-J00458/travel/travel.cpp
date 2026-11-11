#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	int s=0,p=0,z=0;
	if(c1==c2)
	 {  cout<<1;
	   z++;
     }
	else
	   cout<<0;//1
	if(z==1&&s1[0]==s2[0]&&s1[1]==s2[1])
	   cout<<1;
	else
	   cout<<0;//2
     if(s1[0]==s2[0]&&s1[1]==s2[1]&&(s1[2]!=s2[2]&&s1[2]-s2[2]<3)&&s1[2]!='D'&&s1[2]!='F'&&s2[2]!='D'&&s2[2]!='F')  
	  {   cout<<1;
	       s++;
	       p++;
	        if(s1[0]==s2[0]&&s1[1]==s2[1]&&(s1[2]=='D'||s1[2]=='F')&&(s1[2]-s2[2]==1||s1[1]-s2[2]==0))
	  {
	  	cout<<1;
	  	s++;
	  }
		}  
	else 
	    cout<<0;//3
	  
	 if(s==1&&(s1[2]-s2[2]==1||s2[2]-s1[2]==1)||(s1[2]=='D'||s1[2]=='F'))
	     cout<<1;
	 else  cout<<0;
	return 0;
} 
