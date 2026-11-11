#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int cnt=0;
	string a,b,c,d;
	char m,n;
	cin>>a>>b>>c>>d;
	if(a==c)cout<<1;
	else cout<<0;
	for(int i=0;i<=1;i++)
	{
		if(b[i]==d[i])
		{
			cnt=cnt+1;
		}
	}
	if(a==c && cnt==2)cout<<1;
	else cout<<0;
	m=b[2];
	n=d[2];
	int cntt=0,ans=m-n;
	if((m=='A' || m=='B'  ||  m=='C')&&cnt==2&&a==c)
	{
		if(n=='A' || n=='B'  ||  n=='C')
		{
			cout<<1;
			cntt+=1;
			
		}
		else 
		{
			cout<<0;
		}
	}
	else if((m=='D' || m=='F')&&cnt==2&&a==c)
	{
		if(n=='D' || n=='F'){
			cout<<1;
			cntt+=1;
		}
		else
		{
			cout<<0;
		}
	}
	else
	{
		cout<<0;
	}
	if(a==c && cnt==2 && cntt==1 && (ans==1 || ans==-1))cout<<1;
	else cout<<0;
	return 0;
} 
