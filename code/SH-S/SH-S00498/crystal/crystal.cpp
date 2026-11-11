#include<bits/stdc++.h>
using namespace std;
vector<int> a;
int f[1000005];
int df[1000005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	long long n,m;
	cin>>n>>m;
	
	for(int i = 1;i<=n;i++)
	{
		long long x;
		cin>>x;
		if(x>=0)
		{
			if(!f[x]){a.push_back(x);}
			f[x]++;
		}
		else
		{
			if(!df[-x]){a.push_back(x);}
			df[-x]++;
		}
		
		
	}
	
	sort(a.begin(),a.end());
	
	long long sum = 0;
	for(int i = a.size()-1;i>=0;i--)
		{	
			//cout<<"check "<<a[i]<<endl;
			long long cost = m,ans = f[a[i]];
			
			for(int j = 1;j<=m;j++)
			{
				int k = i-j;
				
				if(k<0){
					sum = max(sum,ans);break;
				}
				
				int use = (a[i]-a[k]);
				if(a[k]>=0){use*=f[a[k]];
				}
				else{
					use*=df[-1*a[k]];}
				
				
					if(cost-use>=0)
					{
						cost-=use;
						if(a[k]>=0){ans+=f[a[k]];}
						else{ans+=df[-1*a[k]];}
					}
					else{
						while(cost-(a[i]-a[k])>=0)
						{
							cost-=a[i]-a[k];
							ans++;
						}
						sum = max(sum,ans);
						break;
						}			
				
			}
			//cout<<a[i]<<" ans:"<<ans<<endl;
		}
	
	cout<<sum;
	return 0;
}
