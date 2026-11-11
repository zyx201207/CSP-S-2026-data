#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N=5e5+5;
int n,m,sum,mx,cnt,ans,res,idx,cha[N],s[N],a[N];
bool flag=1,flag2=1,vis=1;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum=abs(a[i]-a[i-1]);
		s[i]=s[i-1]+a[i];
		cha[i]=a[i]-a[i-1];
	}
	sum=a[n]-a[n-1];
	for(int i=2;i<=n;i++)
	{
		if(a[i]-a[i-1]!=sum)flag2=0;
	}
	if(flag2)
	{
		int cnt=0;
		while(1)
		{
			if(cnt>m)break;
			if(cnt>s[n]){idx++;break;}
			cnt+=sum;
			sum+=2;
			idx++;
		}
		cout<<idx;
		return 0;
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		res=0,sum=0,cnt=0;
		for(int j=1;j<=n;j++)
		{
			res+=abs(a[j]-a[i]);
			sum+=res;
			if(res>m)break;
			cnt++;
		}
		mx=max(mx,cnt);
	}
	cout<<mx;
	return 0;
}