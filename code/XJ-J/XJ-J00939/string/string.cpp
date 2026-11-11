#include<bits/stdc++.h>
using namespace std;
const int N = 1e8+5;
#define LL long long 
LL a[N],n,cnt;
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
		for(int j=1;j<=a[i];j++)
		{
			s+=c[i];
		}
	}
	for(int j=1,k=n;j>=k;j++,k--)
	{
		if(s[j]!=s[k])
		{
			s[j]=s[k];
			cnt++;
		}
	}
	cout<<0;
}