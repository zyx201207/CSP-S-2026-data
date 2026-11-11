#include <bits/stdc++.h>
using namespace std;
const int N=500005;
unsigned long long n,m,k,mid,cnt;
signed long long a[N],b[N];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	mid=(n+1)>>1;
	for(int i=1;i<=n;i++)
		b[i]=abs(a[i]-a[mid]);
	sort(b+1,b+1+n);
	k=1;
	while(cnt+b[k]<=m)
	{
		cnt+=b[k];
		k++;
	}
	cout<<k-1;
	return 0;
}
