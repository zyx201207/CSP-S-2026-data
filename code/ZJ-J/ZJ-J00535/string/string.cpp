#include<bits/stdc++.h>
using namespace std;
const int N=200010;
long long ans=0;
int n;
long long a[N];
char c[N];
long long sum=0;
void run()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum+=a[i];
		cin>>c[i];
	}
	int l=1;
	int r=n;
	while(l<r)
	{
		if(c[l]==c[r])
		{
			if(a[l]==a[r])
			{
				l++;
				r--;
			}
			else if(a[l]>a[r])
			{
				a[l]-=a[r];
				r--;
			}
			else if(a[l]<a[r])
			{
				a[r]-=a[l];
				l++;
			}
		}
		if(c[l]!=c[r])
		{
			if(a[l]==a[r])
			{
				ans+=a[l];
				l++;
				r--;
			}
			else if(a[l]>a[r])
			{
				ans+=a[r];
				a[l]-=a[r];				
				r--;
			}
			else if(a[l]<a[r])
			{
				ans+=a[l];
				a[r]-=a[l];				
				l++;
			}
		}
	}
	cout<<ans;
	return ;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	run();
	return 0;
}