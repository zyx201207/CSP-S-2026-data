#include<bits/stdc++.h>
using namespace std;
struct node
{
	long long int a;
	char s;
}q[999905];
long long int i,n,l,r,ans=0;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++)
	cin>>q[i].a>>q[i].s;	
	l=1;r=n;	
	while(l<r)
	{
	if(q[l].s==q[r].s)
	{
	if(q[l].a>q[r].a)	
	{	
	q[l].a-=q[r].a;
	q[r].a=0;
	r--;	
	}
	else
	if(q[l].a<q[r].a)	
	{	
	q[r].a-=q[l].a;
	q[l].a=0;
	l++;	
	}	
	else
	if(q[l].a==q[r].a)	
	{	
	q[l].a=0;q[r].a=0;
	l++;r--;	
	}	
	continue;	
	}	
	if(q[l].a>q[r].a)	
	{
	q[l].a-=q[r].a;
	ans+=q[r].a;
	q[r].a=0;
	r--;	
	}
	else
	if(q[l].a<q[r].a)	
	{
	q[r].a-=q[l].a;
	ans+=q[l].a;
	q[l].a=0;
	l++;	
	}	
	else
	if(q[l].a==q[r].a)	
	{	
	ans+=q[l].a;
	q[l].a=0;q[r].a=0;
	l++;r--;	
	}		
	}
	cout<<ans;
	return 0;
}
