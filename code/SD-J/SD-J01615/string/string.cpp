#include<bits/stdc++.h>
using namespace std;
long long n,a,len,cnt;
char c;
string s=" ";
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	long long aa;
	for(int i=1; i<=n; i++)
	{
		cin>>a>>c;
		for(int j=1; j<=a; j++)
		{
			s+=c;
		}
		len+=a;
	}
	for(long long i=1; i<=len/2; i++)
	{
		if(s[i]!=s[len+1-i]) cnt++;
	}
	cout<<cnt;
	return 0;
}
