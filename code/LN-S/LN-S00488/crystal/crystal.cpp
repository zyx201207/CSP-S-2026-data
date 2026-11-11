#include<bits/stdc++.h>
using namespace std;
long long n,m,a[514514],ans=1;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long m1=m;
	for(long long i=n-1;i>0;i--)
	{
		if(m1>=a[n]-a[i])m1-=(a[n]-a[i]),ans++;
		else break;
	}
	for(long long i=n-1,ans1=ans;i>ans;i--)
	{
		m1+=(a[i+1]-a[i])*(--ans1);
		for(long long j=i-ans1;j>0;j--)
		{
			if(m1>=a[i]-a[j])m1-=a[i]-a[j],ans1++;
			else break;
		}
		ans=max(ans,ans1);
	}
	cout<<ans;
	return 0;
}
/*
cd ..
cd crystal
g++ -O2 -std=c++14 -static crystal.cpp -o crystal
time ./crystal

*/