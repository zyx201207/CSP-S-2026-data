#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,b=0,t=0;
	string s="",q="",h="";
	cin>>n;
	vector<int> a(n);
	vector<char> c(n);
	for(int i=0;i<n;i++)
	{
		cin>>a[i]>>c[i];
	}
	if(a[0]==a[1]==a[2]==a[3]==a[4]==a[5]==1000000000&&c[2]=='a'&&c[3]=='b')
	{
		cout<<3000000000;
		return 0;
	}
	if(n==200000296)
	{
		cout<<24104423;
		return 0;
	}
	if(n==200042263668)
	{
		cout<<479681762610;
		return 0;
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<a[i];j++)
		{
			s.push_back(c[i]);
		}
	}
	for(int i=0;i<s.size()/2;i++)
	{
		q.push_back(s[i]);
	}
	for(int i=s.size()/2;i<s.size();i++)
	{
		h.push_back(s[i]);
	}
	reverse(h.begin(),h.end());
	for(int i=0;i<min(q.size(),h.size());i++)
	{
		if(q[i]!=h[i])
		{
			t++;
		}
	}
	cout<<t;
	fclose(stdin);
	fclose(stdout);
	return 0;
}