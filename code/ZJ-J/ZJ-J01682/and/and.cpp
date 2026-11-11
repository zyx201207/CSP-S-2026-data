#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
long long a[maxn];
int n;
int cnt;
long long ans;
int m;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++)
		cin>>a[i]; 
	for (int i=30;i>=0;i--)
	{
		cnt=0;
		for (int j=1;j<=n;j++)
			if(a[j]&(1<<i))
				cnt++;
		if(cnt<m)
			continue;
		for (int j=1;j<=n;j++)
			if(!(a[j]&(1<<i)))
				a[j]=0;
		ans+=(1ll<<i);
	}
	cout<<ans;
}
