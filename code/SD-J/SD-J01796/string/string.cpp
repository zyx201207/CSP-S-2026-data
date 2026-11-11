#include<bits/stdc++.h>
using namespace std;
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,x,su=1,ans=0;
	char y;
	cin>>n;
	for(long long a=0;a<n;a++)
	{
		cin>>x>>y;
		for(long long a=0;a<x;a++) s=s+y;
		su+=x; 
	}
	su--;
	//cout<<s<<"!@#$%^&*"<<s.size()<<"\n";
	for(long long a=1;a<=s.size();a++)if(s[a]!=s[su+1-a]) ans++;
	cout<<ans/2;
	return 0;
}


