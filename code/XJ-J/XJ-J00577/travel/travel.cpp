#include<bits/stdc++.h> 
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);  
	int c1,c2,f1=0,f2=0,f3=0,s=0;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	 s+=1;
	 else
	 {
	 	f1=1;
	 }
	if(s1[0]==s2[0]&&s1[1]==s2[1]&&f1==0)
	{
	 	s+=1;
	}
	else
	{
		f2=1;
	}
	
	
	if(s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C'&&f1==0&&f2==0)
	{
	 	s+=1;
	}
	if(s1[2]>='D'&&s1[2]<='F'&&s2[2]>='D'&&s2[2]<='F'&&f1==0&&f2==0)
	{
	 	s+=1;
	}
	else
	{
		f3=1;
	}
	


	if(s1[2]=='A'&&s2[2]=='B')
	{
	 	s+=1;
	}
	if(s1[2]=='B'&&s2[2]=='A')
	{
	 	s+=1;
	}
	if(s1[2]=='C'&&s2[2]=='B')
	{
	 	s+=1;
	}
	if(s1[2]=='B'&&s2[2]=='C')
	{
	 	s+=1;
	}
	if(s1[2]=='D'&&s2[2]=='F')
	{
	 	s+=1;
	}
	if(s1[2]=='F'&&s2[2]=='D')
	{
	 	s+=1;
	}
	if(s==0)
	cout<<"0000";
	if(s==1)
	cout<<"1000";
	if(s==2)
	cout<<"1100";
	if(s==3)
	cout<<"1110";
	if(s==4)
	cout<<"1111";
	return 0;		 
}

