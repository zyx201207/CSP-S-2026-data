#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2,cnt;
int main(){ 
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	bool same =false;
	
	for(int i=0;i<=1;i++)
	{
		char cc1=c1[i];
		char cc2=c2[i];
		if(cc1==cc2) same=true;
		else same=false;
	}
	char c=s1[2]-'0';
	char d=s2[2]-'0';
	if(same) cnt+='1';
	else cnt+='0000';
		
	if(s1[0]==s2[0])
	{
		if(s1[1]==s2[1])
		{
			cnt+='1';//pai
			if(s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C') 
			{
				cnt+='1';//ce
				if(c-d==1||d-c==1) cnt+='1';						
				else cnt+='0';
				
			}		
			else if(s1[2]>='D'&&s1[2]<='F'&&s2[2]>='D'&&s2[2]<='F')
			{
				cnt+='1';//c
				if(c-d==1||d-c==1) cnt+='1';
				else cnt+='0';
			
			}
			else cnt+='0';			
		}
		else cnt+='0';//2
	}		
	else cnt+='0';//1
 	if(s1[2]>='A'&&s1[2]<='C'&&s2[2]>='D'&&s2[2]<='F') cnt+='00';
	else if(s2[2]>='A'&&s2[2]<='C'&&s1[2]>='D'&&s1[2]<='F') cnt+='00';
	
	
	cout<<cnt;
	return 0;
}