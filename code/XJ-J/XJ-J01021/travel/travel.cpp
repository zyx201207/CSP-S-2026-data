#include<bits/stdc++.h>
using namespace std;
int i,k,j,m;
char a[100],b[100],a1[100],b1[100],d[5]={'1','1','1','1','1'};
int main()
{
	for(i=1;i<=2;i++)
	cin>>a[i];
	for(i=1;i<=3;i++)
	cin>>b[i];
	for(i=1;i<=2;i++)
	cin>>a1[i];
	for(i=1;i<=3;i++)
	cin>>b1[i];
	
	for(i=1;i<=2;i++)
	if(a[i]!=a1[i])
	{
		d[1]='0';
    }
    
	if(b[1]!=b1[1])
	{
	   d[2]='0';
	}
	
	if(b[2]!=b1[2])
	{
		d[3]='0';
	}
	
	if(b[3]-b1[3]!=1&&b1[3]-b[3]!=1)
	{
		d[4]='0';
	}
	
	for(i=1;i<=4;i++)
	cout<<d[i];
	return 0;
} 