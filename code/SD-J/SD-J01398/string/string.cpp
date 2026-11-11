#include<bits/stdc++.h>
using namespace std;
int n,k,sum;
string s;
char a;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>k;
		cin>>a;
		for(int j=0;j<k;j++)
		{
			s+=a;
		}
	}
	for(int i=0;i<s.size()/2;i++)
	{
		if(s[i]!=s[s.size()-i-1])sum++;
	}
	cout<<sum;
}
