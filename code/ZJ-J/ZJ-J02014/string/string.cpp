#include<bits/stdc++.h>
using namespace std;
long long a[200002];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	char c;
	string s="";
	for(int i=0;i<n;i++)
	{
		cin>>a[i]>>c;
		for(int j=0;j<a[i];j++) s+=c;
	}
	long long sum;
	for(int i=0;i<s.size();i++)
	{
		if(i>=s.size()-i-1) break;
		if(s[i]!=s[s.size()-i-1]) sum++;
	}
	cout<<sum;
}
