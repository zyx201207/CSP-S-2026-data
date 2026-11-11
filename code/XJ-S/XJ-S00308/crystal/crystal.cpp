#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
ll n,m;
ll a[N],cha[N];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n==1)
	{
		cout<<"1";
		return 0;
	}
	sort(a+1,a+1+n);
	if(n<=5000)
	{
		ll aans=1;
		ll last=-1;
		for(int mid=2;mid<=n;mid++)
		{
			ll ccnt=1;
			ll mmm=m;
			for(int j=mid-1;j>=1;j--)
			{
				if(mmm-(a[mid]-a[j])>=0)
				{
					mmm=mmm-(a[mid]-a[j]);
					ccnt++;
				}
			}
			aans=max(aans,ccnt);
			last=ccnt;
		}
		cout<<max(aans,last);
		return 0;
	}
	ll cnt=1,ans=1;
	int tmp=1;
	for(int i=2;i<=n;i++)
	{
		cha[i]=cha[i-1]+(a[i]-a[i-1])*(i-1);
		while(m-cha[i]<0&&tmp<i)
		{
			m+=a[i]-a[tmp];
			tmp++;
			cnt--;
		}
		if(m-cha[i]>=0)
		{
			cnt++;
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
}
