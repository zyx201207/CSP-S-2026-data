#include<bits/stdc++.h>
using namespace std;
int n;
long long a[200010];
char c[200010];
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int len=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i]; 
		while(a[i]--)
		{
			s[++len]=c[i]; 
		} 
	}
	long long cnt=0;
	for(int i=1;i<=(len+1)>>1;i++)
	{
		if(s[i]==s[len+1-i])
		{
			continue;
		}
		else
		{
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
