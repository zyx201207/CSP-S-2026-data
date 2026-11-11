#include<bits/stdc++.h>
using namespace std;
int qwe[]={1,1,1,0,0,0};
int pro[]={1,2,-1,5,-1,-1},prev[]={-1,0,1,-1,-1,3};
int main()
{
	freopen("traval.in","r",stdin);
	freopen("traval.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	int cnt=0;
	int nc1=0,ns1=0,nc2=0,ns2=0;
	while(cnt<=1)
	{
		nc1=nc1*10+c1[cnt++]-'0';
	}
	cnt=0;\
	while(cnt<=1)
	{
		ns1=ns1*10+s1[cnt++]-'0';
	}
	cnt=0;
	while(cnt<=1)
	{
		nc2=nc2*10+c2[cnt++]-'0';
	}
	cnt=0;
	while(cnt<=1)
	{
		ns2=ns2*10+s2[cnt++]-'0';
	}
	cnt=0;
	if(nc1==nc2)
	{
		cout<<1;
		if(ns2==ns1)
		{
			cout<<1;
			if(qwe[s1[2]-'A']==qwe[s1[2]-'A']) cout<<1;
			
		}
		else
		{
			cout<<0<<0;
		}
		bool p=(s1[2]==s2[2] && abs(ns1-ns2)<=1);
		if(((pro[s1[2]-'A']==s2[2]-'A') || (prev[s1[2]-'A']==s2[2]-'A')) && ns1==ns2) p=1;
		//cout<<int(pro[s1[2]-'A']==s2[2]-'A')<<int(prev[s1[2]-'A']==s2[2]-'A')<<int(ns1==ns2);
		cout<<p;
		
	}
	else cout<<0<<0<<0<<0;
	return 0;
 } 
