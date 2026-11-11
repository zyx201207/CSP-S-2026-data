#include<bits/stdc++.h>
using namespace std;
const int N=200010;
using ll=long long;
ll n,pre[200050],ans;
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int ai;char c;
		cin>>ai>>c;
		for(int j=1;j<=ai;j++) s+=c;
	}
	for(int i=0;i<s.size()/2;i++)
	{
		if(s[i]!=s[s.size()-i-1]) ans++;
	}
	cout<<ans;
	return 0;
 } 
