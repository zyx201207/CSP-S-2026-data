#include<bits/stdc++.h>
using namespace std;
long long int a[200005],n,i,s=0,l,j;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	char c;
	string b;
	cin>>n;
	j=0;
	while(n--)
	{
		cin>>a[j]>>c;
		for(i=1;i<=a[j];i++)
		{
			a[i+a[j-1]]=a[j];
			b+=c;
		}
		j=j+a[j]-1;
	}
	l=b.size();
	l=ceil(l*1.0/2);
	j=l-1;
	for(i=0;i<l;i++)
	{
		if(b[i]!=b[l+1-i])
		{
			s+=min(a[i],a[l+1-i]);
			i+=min(a[i],a[l+1-i])-1;
//			j=j-min(a[i],a[l+1-i])+1;
		}
	}
	cout<<s;
	return 0;
}