#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int pre[500005];
int ans[500005];
int f[500005];
int a[500005];
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);//常数较大，需要快读
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	} 
	
	for(int i=1;i<=m;i++)
	{
		memset(pre,0,sizeof(pre));
		memset(f,0,sizeof(f));
		for(int j=n;j>=1;j--)
		{
			if(pre[a[j]]>0){
				f[j]=f[pre[a[j]]];
				pre[a[j]]=j;
			}
			else{
				if(a[j]==i){
					f[j]++;
				}
				else{
					f[j]=f[j+1];
				}
				pre[a[j]]=j;
			}
			//cout<<f[j]<<" ";
			ans[i]+=f[j];
		}
		cout<<(long long)ans[i]<<" ";
	}
} 
