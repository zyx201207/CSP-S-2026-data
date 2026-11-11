#include<bits/stdc++.h>
using namespace std;
string c1,c2,c3,c4,k;
long long int i,k1=1,k2=1,k3=1,k4=1;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>c2>>c3>>c4;
	for(i=0;c1[i]!='\0';i++)
	{
		if(c1[i]!=c3[i])
		{
			k1=0;
			break;
		}
	}
	if(k1==1)
	{
		for(i=0;i<2;i++)
		{
			if(c2[i]!=c4[i])
			{
				k2=0;
				break;
			}
		}
	}
	else
	k2=0;
	if(k2==1)
	{
		if((c2[2]<='C'&&c4[2]<='C')||(c2[3]>='D'&&c4[2]>='D'))
		{
			k3=1;
			if(c2[2]+1==c4[2]||c2[2]-1==c4[2])
			k4=1;
		}   
		else
		{
			k3=0;
			k4=0;
		}   
	}
	else
	{
		k3=0;
		k4=0;
	}
	cout<<char(k1+48)<<char(k2+48)<<char(k3+48)<<char(k4+48);
	return 0; 
}