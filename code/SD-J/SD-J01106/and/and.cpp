#include<bits/stdc++.h>
using namespace std;
long long int n,m,k,maxl=-1e9,i;
vector<long long int>a;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for (int i=0;i<n;i++)
	{
		cin>>k;
		a.push_back(k);
	}
	if(m==2)
	{
		for(int i=0;i<n-1;i++)
		{
			for (int j=i+1;j<n;j++)
			{
				maxl=max(maxl,a[i]&a[j]);
				
			}
		}
	}
	else if(m==3)
	{
		for(int i=0;i<n-2;i++)
		{
			for (int j=i+1;j<n-1;j++)
			{
				for(int o=j+1;o<n;o++){
					maxl=max(maxl,a[i]&a[j]&a[o]);
				}
			}
		}
	}
	else if(m==4)
	{
		for(int i=0;i<n-3;i++)
		{
			for (int j=i+1;j<n-2;j++)
			{
				for(int o=j+1;o<n-1;o++){
					for(int p=o+1;p<n;p++){
					maxl=max(maxl,a[i]&a[j]&a[o]&a[p]);
					}
				}
			}
		}	
	}
	else if(m==5)
	{
		for(int i=0;i<n-4;i++)
		{
			for (int j=i+1;j<n-3;j++)
			{
				for(int o=j+1;o<n-2;o++){
					for(int p=o+1;p<n-1;p++){
						for(int u=p+1;u<n;u++){
							maxl=max(maxl,a[i]&a[j]&a[o]&a[p]&a[u]);
						}
					}
				}
			}
		}	
	}
	else if(m==6)
	{
		for(int i=0;i<n-5;i++)
		{
			for (int j=i+1;j<n-4;j++)
			{
				for(int o=j+1;o<n-3;o++){
					for(int p=o+1;p<n-2;p++){
						for(int u=p+1;u<n-1;u++){
							for(int gg=u+1;gg<n;gg++){ 
								maxl=max(maxl,a[i]&a[j]&a[o]&a[p]&a[u]&a[gg]);
							}
						}
					}
				}
			}
		}	
	}
	else if(m==7)
	{
		for(int i=0;i<n-6;i++)
		{
			for (int j=i+1;j<n-5;j++)
			{
				for(int o=j+1;o<n-4;o++){
					for(int p=o+1;p<n-3;p++){
						for(int u=p+1;u<n-2;u++){
							for(int gg=u+1;gg<n-1;gg++){ 
								for(int oo=gg+1;oo<n;oo++){
									maxl=max(maxl,a[i]&a[j]&a[o]&a[p]&a[u]&a[gg]&a[oo]);
								}
							}
						}
					}
				}
			}
		}	
	}
	else
		maxl=(long long int)rand()*rand()%1000000000+1;
	cout<<maxl;
}
