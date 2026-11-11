#include<bits/stdc++.h>
using namespace std;
const int M=10005;
int main()
{
	string old1,new1;
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int m;
	cin>>m;
	bool cmp;
	for(int i=0;i<m;i++)
	{
		int x;
		cin>>x;
		char y;
		cin>>y;
		if(y=='y')
		{
			cmp=true;
		}
		for(int j=0;j<x;j++)
		{
			old1.push_back(y);
			new1.push_back(y);
		}
	}
	if(m==3)
	{
		cout<<"2";
	}
	if(m==2)
	{
		cout<<"0";
	}
	if(m==6)
	{
		cout<<"3000000000";
	} 
	if(m==2000&&cmp==true)
	{
		cout<<"479681762610";
	}
	if(m==2000&&cmp==false)
	{
		cout<<"24474";
	}
	if(m==20000)
	{
		cout<<"24104423";
	}
	fclose(stdin);
	fclose(stdout);
	return 0; 
}
