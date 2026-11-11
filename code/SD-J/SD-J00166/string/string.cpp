#include <bits/stdc++.h> 
using namespace std;
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	long long a;
	char c;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>c;
		for(long long j=1;j<=a;j++)
		{
			s+=c;
		}
	}
	string fz=s;
	reverse(fz.begin(),fz.end());
	if(fz==s)
		cout<<0;
	else
		cout<<s.size()/2;
	return 0;
}
