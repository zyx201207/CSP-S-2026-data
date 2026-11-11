#include<bits/stdc++.h>//gai
using namespace std;
long long n,a[500010],m,s[500010];//ll
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];	
	}
	sort(a+1,a+1+n);int cnt=0;
	for(long long i=1;i<=n;i++)
	{
		s[i-1]=a[i]-a[i-1];

	}
	for(long long i=0;i<=n;i++)
	{	
	//	if(s[i]==0)	cnt++;
	//	 cout<<s[i]<<' ';
	}//cout<<cnt<<endl;
	long long l=0,r=1;
	long long ans=0,mi=0,v=0;
	while(l<r&&r<=n)
	{
		while(v+(r-l)*s[r]<=m)
		{
			if(r>=n||v>m)	break;
			v=v+(r-l)*s[r];
			r++;
			ans=max(r-l,ans);
		//	cout<<ans<<'v'<<v<<'L'<<l<<'r'<<r<<' ';
	
		}
		l++;
		v=v-s[l];
	}
	cout<<ans++;
}
