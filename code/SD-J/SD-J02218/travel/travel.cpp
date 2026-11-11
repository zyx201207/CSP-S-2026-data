#include<iostream>
using namespace std;
int n,m;
string c,d; 
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);	
	int n,m;
	cin>>n>>c>>m>>d;
	if(n==m)
		cout<<"1";
	else
	{
		cout<<"0000";
		return 0;	
	}
	if(c[0]==d[0]&&c[1]==d[1])
	{
		cout<<"1";
	}	
	else
	{
		cout<<"000";
		return 0;
	}
	if(c[2]-'A'<=2&&c[2]-'A'>=0&&d[2]-'A'<=2&&d[2]-'A'>=0)
	{
		cout<<"1";
	}	
	else if(c[2]-'A'<=4&&c[2]-'A'>=3&&d[2]-'A'<=4&&d[2]-'A'>=3)
	{
		cout<<"1";
	}
	else
	{
		cout<<"00";
		return 0;
	}
	if(c[2]-'A'==d[2]-'A'+1||c[2]-'A'==d[2]-'A'-1)
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
