#include<bits/stdc++.h>
using namespace std;
char s1[20],s2[20];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	
	cin>>c1;
	cin>>s1;
	cin>>c2;
	cin>>s2;
	
	
	if(c1==c2)
		cout<<"1";
	else{
		cout<<"0000";
		return 0;
	}
		
	char n1=s1[0],n1_=s1[1],n2=s2[0],n2_=s2[1],n11=s1[2],n22=s2[2];
	
	if(n1==n2&&n1_==n2_)
	{
		cout<<"1";
	}
	else
	{
		cout<<"000";
		return 0;
	}
	
	if(n11=='C'&&n22=='D')
	{
		cout<<"00";
		return 0;
	}
	if(n11=='A'&&(n22=='B'||n22=='C'))
	{
		cout<<"1";
	}
	else if(n11=='B'&&(n22=='A'||n22=='C'))
	{
		cout<<"1";
	}
	else if(n11=='C'&&(n22=='A'||n22=='B'))
	{
		cout<<"1";
	}
	else if(n11=='D'&&n22=='F')
	{
		cout<<"11";
		return 0;
	}
	else if(n11=='F'&&n22=='D')
	{
		cout<<"11";
		return 0;
	}
	else
	{
		cout<<"00";
		return 0;
	}
	
	if(int(n11)+1==int(n22)||int(n11)-1==int(n22))
	{
		cout<<"1";
		return 0;
	}
	else
	{
		cout<<"0";
		return 0;
	}
	return 0;
} 
