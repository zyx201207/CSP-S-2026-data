#include<bits/stdc++.h>
using namespace std;
string b,t[1000005],c[1000005],d[1000005];
long long int s,n,i,k,m,a,j,l;
int main()
{
	freopen("string.in","r","stdin");
	freopen("string.out","w","stdout");
	cin>>n;
	for(i=1;i<=n;i++)
	{
	cin>>a>>b;
    
	for(k=1;k<=a;k++)
	t[++m]=b;
    } 
	
    
	if(m%2==0)
	 for(i=m/2+1;i<=m;i++)
    {
    	d[++j]=t[i];
    	
	}
	else
	 for(i=m/2+2;i<=m;i++)
    {
    	d[++j]=t[i];
    	
	}
	
	set<string>q;
	for(i=1;i<=m/2;i++)
	{
		q.insert(t[i]);
	}
	
	
	for(i=1;i<=j;i++)
	{
		if(q.count(d[i])==0)
		s++;
	}
	cout<<s;
	return 0;
}