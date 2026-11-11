#include<bits/stdc++.h>
using namespace std;
int n,a[200005],sum,l;
char c[200005];
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		while(a[i]--)s.substr()=c[i];
	}
	l=s.size();
	for(int i=0;i<l;i++)
	{
		if(s[i]!=s[l-i])sum++;
	}
	cout<<sum;
	return 0;
}
