#include<bits/stdc++.h>
using namespace std;
string s1,s2;//³µÏáºÅ 
string x1,x2;//×ùÎ»ºÅ 
int c1=0,c2=0;//³µÏáºÅint 
int p1=0,p2=0;
string da;
int shua;
char z1,z2;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
	cin>>s1>>x1>>s2>>x2;
	//Í¬³µ 
	if(s1[0]=='0')
	{
		c1=int(s1[1]-'0');
	 } 
	else
	{
		for(int i=0;i<=1;i++)
		{
			c1=c1*10+int(s1[i]-'0');
		}
	}
	if(s2[0]=='0')
	{
		c2=int(s2[1]-'0');
	 } 
	else
	{
		for(int i=0;i<=1;i++)
		{
			c2=c2*10+int(s2[i]-'0');
		}
	}
	//c1Óëc2´æ³µÏáºÅ
	int flag1=0;
	if(c1==c2) 
	{
		da+="1"; 
		flag1=1;
	}
	else 
	{
		da+="0";
		cout<<"0000";
		return 0;
	}
	//Í¬ÅÅ 
	
	if(x1[0]=='0')
	{
		p1=int(x1[1]-'0');
		cout<<p1<<" ";
	 } 
	else
	{
		for(int i=0;i<=1;i++)
		{
			p1=p1*10+int(x1[i]-'0');
			cout<<p1<<" ";
		}
	}
	if(x2[0]=='0')
	{
		p2=int(x2[1]-'0');
		cout<<p2<<" ";
	 } 
	else
	{
		for(int i=0;i<=1;i++)
		{
			p2=p2*10+int(x2[i]-'0');
			cout<<p2<<" ";
		}
	}
	int flag=0;
	if(p1==p2) 
	{
		da+="1";
		flag=1;
	} 
	if(p1!=p2)
	{
		da+="0";
	}
	//Í¬Î» 
	z1=char(x1[2]);
	z2=char(x2[2]);
 	if(z1>='A' && z1<='C' && z2>='A' && z2<='C'&& flag)//1×ó2×ó 
	{
		da+="1";
		cout<<z1<<z2<<" ";
	}
	else if(z1>='A' && z1<='C' && z2>='D' && z2<='F'&& flag)//1×ó2ÓÒ 
	{
		da+="0";
		cout<<z1<<z2<<" ";
	}
	else if(z1>='D' && z1<='F' && z2>='D' && z2<='F'&& flag)//1ÓÒ2ÓÒ 
	{
		da+="1";
		cout<<z1<<z2<<" ";
	}
	else//1ÓÒ2×ó 
	{

		da+="0";
		cout<<z1<<z2<<" ";
	}
	//ÁÚ×ù 
	if(!flag) da+="0";
	else if((z1=='A' && z2=='B')|| (z2=='A' && z1=='B')&& flag)
	{
		da+="1";
		cout<<z1<<z2<<" ";
	}
	else if((z1=='B' && z2=='C')|| (z1=='C'&& z2=='B')&& flag)
	{
		da+="1";
		cout<<z1<<z2<<" ";
	}
	else if((z1=='D' && z2=='F')|| (z1=='F'&& z2=='D')&& flag)
	{
		da+="1";
		cout<<z1<<z2<<" ";
	}
	else
	{
		da+="0";
		cout<<z1<<z2<<" ";
	}
	cout<<da;
	return 0;
}

