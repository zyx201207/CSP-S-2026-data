#include<bits/stdc++.h>
using namespace std;
long long int n,a,ans=0,l,r=0,b[100000000],i,k=0;
char c;

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	while(n--)
	{
		cin>>a>>c;
		r+=a;
		for(i=1;i<=a;i++)
		{
			b[++k]=c;
		}
	}
    l=1;
    while(l<=r)
    {
    	if(b[l]!=b[r])
    	ans+=1;
    	l++;
    	r--;
	}
	cout<<ans;
	return 0;
}