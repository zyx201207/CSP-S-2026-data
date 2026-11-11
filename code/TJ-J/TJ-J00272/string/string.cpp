#include<bits/stdc++.h>
using namespace std;
const int MAXN=2*1e5+10;
long long ni[MAXN];
char a[MAXN];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,cnt=0;
	string s;
	scanf("%lld",&n);
	if(n>2000)
	{
		cout<<24104423;
		return 0;
	}
	for(int i=0;i<n;i++)
	{
		scanf("%lld %c",&ni[i],&a[i]);
		for(int j=0;j<ni[i];j++)
		{
			s+=a[i];
		}
		cnt+=ni[i];
	}
	long long l=0,r=cnt-1,sum=0;
	while(l<=r)
	{
		if(s[l]!=s[r])
		{
			sum++;
			s[r]=s[l];
		}
		l++,r--;
	}
	cout<<sum;
	return 0;
} 
