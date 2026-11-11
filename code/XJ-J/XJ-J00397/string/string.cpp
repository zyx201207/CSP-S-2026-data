#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long int n,a[N],t,cnt,x;
char c[N];
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		t+=a[i];
		for(int i=1;i<=a[i];i++)
		{
			s+=c[i];
		}
	}		
	for(int i=1+x*a[1],j=n-x*a[1];i<=t/2;i++,j--)
	{
		if(s[i]!=s[j])
		{
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}