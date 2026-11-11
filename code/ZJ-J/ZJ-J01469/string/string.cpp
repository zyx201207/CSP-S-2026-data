#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,i,l,cnt,j;
char ch;
string s="";
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>l>>ch;
		for(j=1;j<=l;j++)
			s+=ch;
	}
	ll n=s.size();
	for(i=0;i<n/2;i++)
		if(s[i]!=s[n-i+1]) cnt++;
	cout<<cnt;
	return 0;
}