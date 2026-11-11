#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,k,ans[1000000];
vector<ll> res;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>k;
	for(ll i=0;i<n;i++)
		cin>>ans[i];
	for(ll i=0;i<n;i++)
	{
		if(ans[i]==0)
		{
			cout<<0<<endl;
			return 0;
		}
	}
	if(k==1)
	{
		sort(ans+0,ans+n);
		cout<<ans[n-1]<<endl;
		return 0;
	}
	if(k==2)
	{
		for(ll i=0;i<n;i++)
		{
			for(ll j=i+1;j<n;j++)
			{
				res.push_back(ans[i]&ans[j]);
			}
		}
		sort(res.begin(),res.end());
		cout<<res.back()<<endl;
		return 0;
	}
	if(k==n)
	{
		ll cnt=ans[0];
		for(int i=1;i<n;i++)
			cnt&=ans[i];
		cout<<cnt<<endl;
		return 0;
	}
	if(k==3)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				for(int t=j+1;t<n;t++)
				{
					res.push_back(ans[i]&ans[j]&ans[t]);
				}
			}
		}
		sort(res.begin(),res.end());
		cout<<res.back()<<endl;
		return 0;
	}
	if(k==4&&n<=1000)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				for(int t=j+1;t<n;t++)
				{
					for(int a=t+1;a<n;a++)
						res.push_back(ans[i]&ans[j]&ans[t]&ans[a]);
				}
			}
		}
		sort(res.begin(),res.end());
		cout<<res.back()<<endl;
		return 0;
	}
	if(k==5&&n<=1000)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				for(int t=j+1;t<n;t++)
				{
					for(int a=t+1;a<n;a++)
						for(int w=a+1;w<n;w++)
							res.push_back(ans[i]&ans[j]&ans[t]&ans[a]&ans[w]);
				}
			}
		}
		sort(res.begin(),res.end());
		cout<<res.back()<<endl;
		return 0;
	}
	if(k==6&&n<=1000)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				for(int t=j+1;t<n;t++)
				{
					for(int a=t+1;a<n;a++)
						for(int w=a+1;w<n;w++)
							for(int q=w+1;q<n;q++)
								res.push_back(ans[i]&ans[j]&ans[t]&ans[a]&ans[w]&ans[q]);
				}
			}
		}
		sort(res.begin(),res.end());
		cout<<res.back()<<endl;
		return 0;
	}
	if(k==7&&n<=1000)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				for(int t=j+1;t<n;t++)
				{
					for(int a=t+1;a<n;a++)
						for(int w=a+1;w<n;w++)
							for(int q=w+1;q<n;q++)
								for(int p=q+1;p<n;p++)
									res.push_back(ans[i]&ans[j]&ans[t]&ans[a]&ans[w]&ans[q]&ans[p]);
				}
			}
		}
		sort(res.begin(),res.end());
		cout<<res.back()<<endl;
		return 0;
	}
	if(k==8&&n<=1000)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				for(int t=j+1;t<n;t++)
				{
					for(int a=t+1;a<n;a++)
						for(int w=a+1;w<n;w++)
							for(int q=w+1;q<n;q++)
								for(int p=q+1;p<n;p++)
									for(int x=p+1;x<n;x++)
										res.push_back(ans[i]&ans[j]&ans[t]&ans[a]&ans[w]&ans[q]&ans[p]&ans[x]);
				}
			}
		}
		sort(res.begin(),res.end());
		cout<<res.back()<<endl;
		return 0;
	}
	if(k==9&&n<=1000)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				for(int t=j+1;t<n;t++)
				{
					for(int a=t+1;a<n;a++)
						for(int w=a+1;w<n;w++)
							for(int q=w+1;q<n;q++)
								for(int p=q+1;p<n;p++)
									for(int x=p+1;x<n;x++)
										for(int y=x=1;y<n;y++)
											res.push_back(ans[i]&ans[j]&ans[t]&ans[a]&ans[w]&ans[q]&ans[p]&ans[x]&ans[y]);
				}
			}
		}
		sort(res.begin(),res.end());
		cout<<res.back()<<endl;
		return 0;
	}
	if(k==10&&n<=1000)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				for(int t=j+1;t<n;t++)
				{
					for(int a=t+1;a<n;a++)
						for(int w=a+1;w<n;w++)
							for(int q=w+1;q<n;q++)
								for(int p=q+1;p<n;p++)
									for(int x=p+1;x<n;x++)
										for(int y=x=1;y<n;y++)
											for(int z=y+1;z<n;z++)
												res.push_back(ans[i]&ans[j]&ans[t]&ans[a]&ans[w]&ans[q]&ans[p]&ans[x]&ans[y]&ans[z]);
				}
			}
		}
		sort(res.begin(),res.end());
		cout<<res.back()<<endl;
		return 0;
	}
	cout<<0<<endl;
	return 0;
}
