#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500005];
int vis[500005];
int cnt[33];
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);//常数较大，需要快读
	int n,m;
	int ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=30;i++){
		//考虑第i位
		memset(cnt,0,sizeof(cnt));
		for(int j=1;j<=n;j++)
		{
			if(vis[j]==1){
				continue;
			}
			int cur=0;
			for(int k=30;k>=0;k--){
				if(a[j]&(1<<k)){
					cnt[k]++;
				}
			}
		}
		int mx=-1;
		for(int k=30;k>=0;k--)
		{
			if(cnt[k]>=m){
				mx=k;
				break;
			}
		}
		if(mx==-1){
			break;
		}
		for(int j=1;j<=n;j++)
		{
			if(vis[j]){
				continue;
			}
			if(a[j]&(1<<mx)){
				a[j]-=(1<<mx);//不再计入 
			}
			else{
				vis[j]=1;//不再查找 
			}
		}
		ans=ans|(1<<mx);
	}
	cout<<ans;
} 
