#include<bits/stdc++.h>
using namespace std;
const long long N=1e5+1;
long long a[N],b[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n==1)
	{
		cout<<1;
		return 0;
	}
	sort(a+1,a+1+n);
	if(m==0)
	{
		int cnt=0,l=0;
		for(int i=1;i<=n;i++)
		{
			int k=a[i];
			if(k==a[i-1]||i==1)
			{
				l++;
				cnt=max(cnt,l); 
			}
			else
			{
				l=1;
			} 
		}
		cout<<cnt;
		return 0;
	}
	for(int i=2;i<=n;i++)
	{
		b[i]=a[i]-a[i-1];
	}
	int dp=b[2],s=0;
	for(int i=2;i<=n;i++)
	{
		if(dp<=b[i])
		{
			dp=b[i];
			s=i;
		}
	}
	s--;
	int ans=1;
	if(s>2)
	{
		int j=b[s];
		for(int i=s;i>=2;i--)
		{
			if(m>=j)
			{
				m-=j;
				j+=b[i-1];
			}
			else
			{
				cout<<ans;
				return 0;
			}
		}
	}
	else
	{
		int i=2,j=b[2];
		while(m>0)
		{
			if(m>j)
			{
				j=j*(i-1);
				m-=j;
				ans++;
				j+=m;
			}
		}
		cout<<ans;
		return 0;
	}
	while(m>=(s-1)*b[s+1])
	{
		m-=(s-1)*b[s+1];
		ans++;
		s++;
	}
	cout<<ans;
}

