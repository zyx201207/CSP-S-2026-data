#include<bits/stdc++.h>
using namespace std;
long long ans,n,q;
char c;
string str;
int main()
{

	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>q>>c;
		for(int i=1;i<=q;i++)
			str+=c;
	}
	for(int i=0;i<str.size()/2;i++)
	{
		if(str[i]!=str[str.size()-i-1])
			ans++;
	}
	cout<<ans;
	return 0;
}