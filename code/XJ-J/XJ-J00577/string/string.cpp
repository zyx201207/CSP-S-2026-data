#include<bits/stdc++.h> 
using namespace std;
long long int 	n,x,len,m=0,i,k=0,ans=0;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);  
	string s1,s2,s,l,s1d;
	cin>>n;
	while(n--)
	{
		cin>>x>>s;
		m+=x;
		while(x--)
		{
			l+=s;
		}
		
	}
	len=int(m*1.0/2);
	if(len%2!=0)
	k=1;
	for(i=len-1;i>=0;i--)
	s1+=l[i];
	for(i=len+k;i<m;i++)
	s2+=l[i];
	for(i=0;i<len;i++)
	{
		if(s1==s2)
		{
			cout<<0;
			return 0;
		}
		if(s1[i]!=s2[i])
		ans++; 
	}
	cout<<ans;
	return 0;
}
