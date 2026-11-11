#include<bits/stdc++.h> 
using namespace std;
long long int i,j,a,n,m,b,c,l,r,sum;
string s,x;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>a;
	for(i=1;i<=a;i++)
	{
		cin>>n>>x;
		while(n--)
		{
			s=s+x;
		}
	}
	if(s.size()%2==1)
	{
		sum=0;
		l=r=(s.size()+1)/2-1;
	}
	else
	{
	sum=1;
	l=s.size()/2-1;
	r=s.size()/2;
    }
		  for(i=0,j=s.size()-1;i<l,j>r;i++,j--)
		  {
		  	if(s[i]!=s[j])
		  	sum++;
	}
	cout<<sum;
	return 0;
}
