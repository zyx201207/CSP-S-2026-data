#include<bits/stdc++.h>
using namespace std;
int main()
{
	//~ freopen("string.in","r",stdin);  
	//~ freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	long long n,i,j,s=0,a[200010]={ },ans,b=0;
	char c[200010],t[200010]=" ";
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		s+=a[i];
	}
	for(i=1;i<=n;i++)
	{
		char d=c[i];
		for(j=b;j<a[i]+b;j++)	
			t[j]=d;	
		b=a[i];
	}
	ans=n/2;
	for(i=1;i<=ans;i++)
	{
		for(j=n;j>=ans;j--)
		{
			if(t[i]!=t[j]) s++;
		}
	}
	cout<<s;
	return 0;
}
