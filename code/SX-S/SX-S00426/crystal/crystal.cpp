#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,t,s,cnt,sum,maxv=1;
long long m,a[N],p[N];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)p[i]=a[i]-a[i-1];
	if(p[1]==p[2]&&p[2]==p[3]&&p[n-2]==p[n-1]&&p[n-1]==p[n])
	{
		cnt=1;
		s=p[1];
		sum=s;
		while(sum<=m)
		{
			cnt++;
			s+=p[1];
			sum+=s;
		}
		cout<<cnt;
		return 0;
	}
	for(int i=n;i>1;i--)
	{
		t=i;
		s=p[i];
		cnt=1;
		sum=s;
		while(sum<=m)
		{
			cnt++;
			t--;
			s+=p[t];
			sum+=s;
		}
		if(cnt>=i-1&&cnt>=maxv)
		{
			cout<<cnt;
			return 0;
		}
		maxv=max(maxv,cnt);
	}
	cout<<maxv;
	return 0;
}