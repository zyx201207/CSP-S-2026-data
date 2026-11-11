#include<bits/stdc++.h>
using namespace std;
long long int n,m,i,j,l,r,a,k,s,mid,w;
string b,c;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	while(n--)
	{
		cin>>a>>b;
		k+=a;
		for(i=1;i<=a;i++)
		c+=b;	
	}
	mid=k/2;
	w=mid;
	if(w%2==0)
	{
		l=mid;
		r=mid+1;
	}
	else
	{
		l=mid-1;
		r=mid+1;
	}
	
	while(r<k)
	{
		if(c[r]!=c[l])
		{
			c[r]=c[l];
			s++;
		}
		l--;
		r++;
	}
	cout<<s;
	return 0;
}