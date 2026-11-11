#include<bits/stdc++.h>
using namespace std;
long long n;
int d[200001];
long long f[200001],ans;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		long long a;
		char c;
		cin>>a>>c;
		f[i]=a;
		d[i]=(c-'a');
	}
	
	int l=1,r=n;
	while(l<=r)
	{
		if(d[l]!=d[r])
		{
			ans+=min(f[l],f[r]);
			if(f[l]<f[r])
			{
				f[r]-=f[l];
				l++;
			}
			else if(f[l]>f[r])
			{
				f[l]-=f[r];
				r++;
			}
			else if(f[l]==f[r])
			{
				l++;
				r--;
			}
		}
		else
		{
			if(f[l]<f[r])
			{
				f[r]-=f[l];
				l++;
			}
			else if(f[l]>f[r])
			{
				f[l]-=f[r];
				r--;
			}
			else if(f[l]==f[r])
			{
				l++;
				r--;
			}
		}
	}
	cout<<ans;	
	return 0;
}

