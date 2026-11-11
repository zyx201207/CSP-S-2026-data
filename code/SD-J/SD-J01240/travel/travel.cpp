#include<bits/stdc++.h>
using namespace std;
int s,x,y,t;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	for(int i=0;i<2;i++)
	{
		if(a[i]!=c[i])
		{
			cout<<"0000";
			return 0;
		}
	}
	cout<<"1";
	char v=d[2],z=b[2];
	for(int i=0;i<2;i++)
	{
		t*=10;
		t+=(b[i]-'0');
		x*=10;
		x+=(d[i]-'0');
	}
	if(x==t) cout<<"1";
	else
	{
		cout<<"000";
		return 0; 
	}
	if(v=='F'&&z=='D'||z=='F'&&v=='D')
	{
		cout<<"1";
	}
	else
	{
		if(v!='D'&&z!='D'&&v!='F'&&z!='F')
		{
			if((v-1==z)||(v+1==z)||(v-2==z)||(v+2==z))
			{
				cout<<"1";
			}
			else 
			{
				cout<<"00";
				return 0;
			}
		}
		else 
		{
			cout<<"00";
			return 0;
		}
	}
	if((z!='A'&&v!='C')&&(v!='A'&&z!='C'))
	{
		cout<<"1";
		return 0;
	}
	cout<<"0";
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 
