#include<bits/stdc++.h>
using namespace std;
string a;
int cnt=0;
int b[200005];
char t[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	long long ans=0;
	for(int i=1;i<=n;i++)
	{
		cin>>b[i]>>t[i];
	}
	int i=1,j=n;
	int l=b[1],r=b[n];
	while(i<j)
	{
		
		if(t[i]!=t[j])
		{
			ans+=min(l,r);
		}
		if(l>r)
		{
			j--;
			l-=r;
			r=b[j];
		}
		else if(l<r)
		{
			i++;
			r-=l;
			l=b[i];
		}
		else
		{
			i++,j--;
			l=b[i],r=b[j];
		}
	}
	cout<<ans;
	return 0;
} 
