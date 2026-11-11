#include<bits/stdc++.h>
using namespace std;
int n,a[200005],cnt;
char c[200005];
string s;
bool f(string x)
{
	string b;
	for(int k=x.size()-1;k>=0;k--)
	b+=x[k];
	if(x==b)
	return true;
	return false;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i]>>c[i];
		for(int j=0;j<a[i];j++)
		s+=c[i];
	}
	if(f(s))
	{
		cout<<0;
		return 0;
	}
	int l=0,r=s.size();
	while(l<r)
	{
		if(s[l]!=s[r])
		{
			s[l]=s[r];
			cnt++;
		}
		l++;
		r--;
	}
	cout<<cnt;
	return 0;
}
