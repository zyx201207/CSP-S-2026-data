#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int n,m,a[N],b[N],ans=1,cnt=1,sum,p,q;
signed main(){
	ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		if (a[i]==i) p++;
	}
	if (p==n)
	{
		for (int i=1;i<=N;i++)
			if (i<=m) m-=i;
			else
			{
				cout<<i;
				return 0;
			}
		cout<<"0";
		return 0;
	}
	for (int i=1;i<n-1;i++)
		if (a[i+1]-a[i]==a[i+2]-a[i+1]) q++;
		else break;
	if (q==n-2)
	{
		for (int i=1;i<=N;i++)
			if (i*(a[2]-a[1])<=m) m-=i*(a[2]-a[1]);
			else
			{
				cout<<i;
				return 0;
			}
		cout<<"0";
		return 0;
	}
	sort(a+1,a+1+n);
	for (int i=1;i<n;i++) b[i]=a[i+1]-a[i];
	for (int i=1;i<n;i++)
	{
		if (sum+b[i]*cnt<=m) sum+=b[i]*cnt,cnt++,ans=max(ans,cnt);
		else
		{
			while (sum+b[i]*cnt>m)
			{
				sum-=(a[i+1]-a[i-cnt+1]);
				cnt--;
			}
			sum+=b[i]*cnt,cnt++;
		}
	}
	cout<<ans;
	return 0;
}
