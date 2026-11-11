#include<bits/stdc++.h>
using namespace std;
long long n,a[200005];
char c[200005];
long long cnt,len;
string s;
int main()
{
	
	freopen("string.in","r",stdin);
	freopen("string.out","W",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		scanf("%d %c",&a[i],&c[i]);
		while(a[i]--)
		{
			s+=c[i];
		}
	}
	long long len=s.size();
	for(int i=0;i<=len/2;i++)
	{
		if(s[i]!=s[len-i-1])
		{
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
