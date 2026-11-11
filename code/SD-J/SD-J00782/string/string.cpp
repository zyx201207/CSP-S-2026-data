#include<iostream>
#include<cstdio>
using namespace std;
long long l,a[200000001],s=1,d[28],ma=-10001,p,ans=0;
char b[200000001],c,x;
int main()
{
	freopen("string.in.txt","r",stdin);
	freopen("string.out.txt","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>l;
	for(long long i=1;i<=l;i++)
	{
		cin>>a[i];
		cin>>c;
		for(int k='a';k<='z';k++)
		{
			if(c==k)
			{
				d[k-'a'+1]+=a[i];
			}
		}
		for(long long j=s;j<=s+a[i];j++)
		{
			b[j]=c;
		}
		s+=a[i];
	}
	for(long long i=1;i<=s/2;i++)
	{
		if(b[i]!=b[s-i+1])
		{
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
