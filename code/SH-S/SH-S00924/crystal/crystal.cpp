#include <bits/stdc++.h>
using namespace std;
long long a[500005],d[500005],ans,b,c,l,m,n,r,sum;
bool B;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	c=m;
	B=1;
	for(int i=0;i<n;i++)cin>>a[i];
	sort(a,a+n);
	for(int i=1;i<n;i++)
	{
		d[i]=a[i]-a[i-1];
		if(i!=1&&d[i]!=d[i-1])B=0;
	}
	if(B==1)
	{
		b=a[1]-a[0];
		while(m>=b*ans&&n>ans)
		{
			m-=b*ans;
			ans++;
		}
		cout<<ans;
	}
	else
	{
		ans=1;
		while(n>r+1)
		{
			r=ans+l-1;
			while(m<ans*d[r+1])
			{
				m+=sum;
				sum-=d[l];
				sum+=d[r+1];
				l++;
				r=ans+l-1;
				m-=ans*d[r];
			}
			if(n>r+1)
			{
				m-=ans*d[r+1];
				sum+=d[r+1];
				ans++;
				r++;
			}
		}
		cout<<ans;
	}
	return 0;
}
