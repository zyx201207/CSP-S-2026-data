#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	int r1,x1;
	string r2,x2;
	bool rlr=1,xlr=1;//0Ϊl,1Ϊr 
	bool a1=0,a2=0,a3=0,a4=0;
	cin>>r1>>r2>>x1>>x2;
	if(r1==x1)
	{
		a1=1;
	}
	if(a1&&r2[0]==x2[0]&&r2[1]==x2[1])
	{
		a2=1;
	}
	if(a2&&r2[2]=='A'||r2[2]=='B'||r2[2]=='C')
	{
		rlr=0;
	}
	if(a2&&x2[2]=='A'||x2[2]=='B'||x2[2]=='C')
	{
		xlr=0;
	}
	if(a2&&xlr==rlr)
	{
		a3=1;
	}
	if(a3&&(r2[2]+1==x2[2]||r2[2]-1==x2[2]))
	{
		a4=1;
	}
	cout<<a1<<a2<<a3<<a4;
	fclose(stdin);
	fclose(stdout);
	return 0; 
}
