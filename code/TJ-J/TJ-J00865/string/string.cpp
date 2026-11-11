#include<bits/stdc++.h>
using namespace std;
int n;
long long l=0,r=0,ll=0,rr=0;
long long s=0,ans=0;
long long a[200005]={0};
char c[200005]={0};
void sl(int i)
{
	if(l+a[i]>s/2)
	{
		ll=s/2-l;
		l=s/2;
	}
	else
	{
		l+=a[i];
		ll=a[i];
	}
}
void sr(int j)
{
	if(r+a[j]>s/2)
	{
		rr=s/2-r;
		r=s/2;
	}
	else
	{
		r+=a[j];
		rr=a[j];
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i=0;i<n;i++)
	{
		cin >> a[i] >> c[i];
		s+=a[i];
	}
	sl(0);
	sr(n-1);
	for(int i=0,j=n-1;i<=j;)
	{
		if(rr==ll)
		{
			if(c[i]==c[j])
			{
				i++;
				j--;
			}
			else
			{
				ans+=ll;
				i++;
				j--;
			}
			sl(i);
			sr(j);
		}
		else if(rr>ll)
		{
			if(c[i]!=c[j])
			{
				ans+=ll;
			}
			rr-=ll;
			i++;
			sl(i);
		}
		else if(rr<ll)
		{
			if(c[i]!=c[j])
			{
				ans+=rr;
			}
			ll-=rr;
			j--;
			sr(j);
		}
	}
	cout << ans;
	return 0;
}
