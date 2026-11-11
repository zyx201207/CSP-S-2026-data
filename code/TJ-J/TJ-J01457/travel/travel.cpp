#include<bits/stdc++.h>
using namespace std;
string nr,sr,nz,sz;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>nr>>sr>>nz>>sz;
	if(nr!=nz)
	{
		cout<<"0000";
		return 0;
	}
	int lr=sr.size()-1;
	int lz=sz.size()-1;
	cout<<1;
	char r=sr[lr];
	char z=sz[lz];
	string numr="";
	string numz="";
	for(int i=0;i<lr;i++)
	{
		numr+=sr[i];
	}
	for(int i=0;i<lz;i++)
	{
		numz+=sz[i];
	}
	if(numr!=numz)
	{
		cout<<"000";
		return 0;
	}
	cout<<1;
	if((r=='A'||r=='B'||r=='C')&&(z=='D'||z=='F'))
	{
		cout<<"00";
		return 0;
	}
	if((z=='A'||z=='B'||z=='C')&&(r=='D'||r=='F'))
	{
		cout<<"00";
		return 0;
	}
	cout<<1;
	if(r=='A')
	{
		if(z=='C')
		{
			cout<<0;
			return 0;
		}
	}
	if(r=='C')
	{
		if(z=='A')
		{
			cout<<0;
			return 0;
		}
	}
	cout<<1;
	return 0;
}
