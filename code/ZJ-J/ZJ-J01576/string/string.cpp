#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long n,k,answer,a[N],s[N];
char c[N];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		s[i]=k+1;
		k+=a[i];
	}
	s[n+1]=k+1;
	for(long long i=1;i<=k/2;)
	{
		int l=upper_bound(s+1,s+n+2,i)-s-1;
		int r=upper_bound(s+1,s+n+2,k-i+1)-s-1;
		if(c[l]!=c[r])
		{
			answer+=min(s[l+1]-i,(k-i+1)-s[r-1]);
		}
		i+=min(s[l+1]-i,(k-i+1)-s[r-1]);
	}
	cout<<answer<<endl;
	return 0;
}
