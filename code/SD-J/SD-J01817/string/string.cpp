#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#include<cstring>
#include<queue>
#include<vector>
#include<stack>
#include<bits/stdc++.h>
#include<cmath>
#define ll long long
#define endl '\n'
using namespace std;
const int N=2e5+10;
ll n,a[N];
char c[N];
ll ans=0;
int l=0,r=0;
ll restl=0,restr=0;
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		char x;
		cin>>a[i]>>c[i];
	}
	restl=a[1],restr=a[n];
	l=1,r=n;
	ans=0;
	while(l<r)
	{
		if(c[l]!=c[r])
		{
			ans+=min(restl,restr);
		}
		if(restl<restr)
		{
			l++;
			restr-=restl;
			restl=a[l];
		}
		else if(restl>restr)
		{
			r--;
			restl-=restr;
			restr=a[r];
		}
		else
		{
			l++;
			r--;
			restl=a[l];
			restr=a[r];
		}
	}
	cout<<ans;
	return 0;
}
