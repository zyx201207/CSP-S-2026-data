#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=5e5+10;
ll a[N],b[N];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n,i,j,max_cnt=INT_MIN,cnt;
	ll m,sum=0;
	cin>>n>>m;
	for(i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	b[1]=0;
	b[2]=a[2]-a[1];
	bool f=1;
	for(i=3;i<=n;i++) 
	{
		b[i]=a[i]-a[i-1];
		if(b[i]!=b[i-1]) f=0;
	}
	if(f==1)
	{
		ll c=b[2];
		cnt=1;
		for(i=2;i<=n;i++)
		{
			sum+=c*(i-1);
			if(m>=sum) cnt++;
			else break;
		}
		cout<<cnt;
		return 0;
	}
	for(i=1;i<n;i++)
	{
		sum=0;cnt=1;
		for(j=i+1;j<=n;j++)
		{        
			sum+=b[j]*(j-i);
			if(m>=sum) cnt++;
			else break;
		}
		max_cnt=max(max_cnt,cnt);
		if(max_cnt==n) break;
	}
	cout<<max_cnt;
	return 0;
}
