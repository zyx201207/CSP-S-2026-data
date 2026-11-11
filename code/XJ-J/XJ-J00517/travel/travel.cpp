#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	bool flag[4]={false,false,false,false};
	
	if(c1==c2)
	{
		flag[0]=true;
	}
	else
	{
		cout<<"0000";
		return 0;
	}
	string a,b;
	a+=s1[0];
	a+=s1[1];
	b+=s2[0];
	b+=s2[1];
	
	if(a==b)
	{
		flag[1]=true;
	}
	else
	{
		cout<<flag[0]<<flag[1]<<"00";
		return 0;
	}
	
	if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C'&&s2[2]=='A'||s2[2]=='B'||s2[2]=='C')
	{
		flag[2]=true;
	}
	if(s1[2]=='D'||s1[2]=='E'&&s2[2]=='D'||s2[2]=='E')
	{
		flag[2]=true;
	}
	
	int d=abs(s1[2]-s2[2]);
	if(d==1&&flag[2]==true)
	{
		flag[3]=true;
    }
    
	for(int i=0;i<4;i++)
	{
		cout<<flag[i];
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}