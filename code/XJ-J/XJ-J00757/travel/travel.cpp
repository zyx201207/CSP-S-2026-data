#include<bits/stdc++.h>
using  namespace  std;
string c1,s1,c2,s2;
int a[50],b[50],i,k,j;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	for(i=1;i<=s1.size()-1;i++)
	a[++k]=s1[i]-'0';
	for(i=1;i<=s2.size()-1;i++)
	b[++j]=s2[i]-'0';
	if(c1==c2)
	{
	    cout<<"1";
	}
	else
	{
	    cout<<"0";
    }
    
	if((c1==c2)&&(a[0]==b[0]&&a[1]==b[1]))
	{
	    cout<<"1";
	}
	else
	{
	    cout<<"0";
    }
    
	if((c1==c2)&&(a[0]==b[0]&&a[1]==b[1])&&((a[2]>='A'&&a[2]<='C')&&(b[2]>='A'&&b[2]<='C')||(a[2]=='D'&&b[2]=='F'||a[2]=='F'&&b[2]=='D')))
	{
	    cout<<"1";
	}
	else
	{
	    cout<<"0";
    }
    
	if((c1==c2)&&(a[0]==b[0]&&a[1]==b[1])&&((a[2]>='A'&&a[2]<='C')&&(b[2]>='A'&&b[2]<='C')||(a[2]=='D'&&b[2]=='F'||a[2]=='F'&&b[2]=='D'))&&(a[i+1]==b[i]))
	{
	    cout<<"1";
	}
	else
	{
	    cout<<"0";
	}
	return 0;
}