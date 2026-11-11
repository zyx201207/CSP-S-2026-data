#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long a[N],cha[N];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	long long m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n-1;i++) cha[i]=a[i+1]-a[i];
	long long zong=0,ans=0,num=0,maxn=0;
	int cnt=1;
	for(int i=1;i<=n-1;i++)
	{
		ans++;
		zong+=ans*cha[i];
		num+=cha[i];
		if(zong<=m) maxn=max(ans+1,maxn);
		else
		{
			while(zong>m&&cnt<=i)
			{
				ans--;
				zong-=num;
				num-=cha[cnt];
				cnt++;
			}
		}
	}
	cout<<maxn;
	return 0;
} 
