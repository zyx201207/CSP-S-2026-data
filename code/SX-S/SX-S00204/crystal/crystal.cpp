#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5+10;

int n,m;
int a[N];
int b[N];
int sum[N];
int ans=1;

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	bool flagB=1;
	for(int i=2;i<=n;i++)
	{
		b[i-1]=a[i]-a[i-1];
		if(i!=2&&b[i-1]!=b[i-2])flagB=0;
	}
	if(flagB)
	{
		int pos=n;
		for(int i=1;i<=n;i++)
		{
			sum[i]=sum[i-1]+i-1;
			if(sum[i]>m)
			{
				pos=i-1;
				break;
			}
			else if(sum[i]==m) 
			{
				pos=i;
				break;
			}
		}
		cout<<pos;
		return 0;
	}
	
	bool flag=0;
	int tmp=0;
	int oo=-1;
	for(int i=1;i<=n;i++)
	{
		if(b[i]==0)
		{
			if(flag)
			{
				tmp++;
			}
			else
			{
				flag=1;
				tmp=1;
			}
		}
		else
		{
			flag=0;
			tmp=0;
		}
		oo=max(oo,tmp);
	}
	for(int i=n-1;i>=1;i--)
	{
		//if(i!=n-1&&b[i]==0&&b[i-1]==0) continue;
		int s=0;
		int cnt=1;
		for(int j=i;j>=1;j--)
		{
			if(b[j]==0)
			{
				cnt++;
				continue;
			}
			int cha=b[j];
			cha*=cnt;
			if(s+cha>m) break;
			else
			{
				cnt++;
				s+=cha;
			}
			
		}
		ans=max(ans,cnt);
	}
	ans=max(ans,oo);
	cout<<ans;
	//cout<<ans;
	/*
	sort(b+1,b+n);
	int cnt=1;
	int s=0;
	for(int i=1;i<n;i++)
	{
		if(a[i]==a[i+1])
		{
			cnt++;
			continue;
		}
		int cha=a[i+1]-a[i];
		cha*=cnt;
		if(s+cha>m) break;
		else
		{
			cnt++;
			s+=cha;
		}
	}
	*/
	return 0;
}
