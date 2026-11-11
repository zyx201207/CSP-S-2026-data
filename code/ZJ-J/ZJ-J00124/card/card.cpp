#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500010];
int cnt[500010];
bool vis[500010];
int ans[500010];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(n<=500){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++)
				vis[j]=0;
			for(int j=1;j<=m;j++)
				cnt[j]=0;
			for(int j=i;j<=n;j++){
				cnt[a[j]]++;
				int k=j-1;
				while(k>=i&&cnt[a[j]]>=2&&(vis[k]||a[k]!=a[j]))
					vis[k]=true,cnt[a[k]]--;
				if(cnt[a[j]]>=2)
					cnt[a[j]]--;
			}
			for(int j=1;j<=m;j++)
				ans[j]+=(cnt[j]>=1);
		}
		for(int i=1;i<=m;i++)
			cout<<ans[i]<<" ";
		return 0;
	}
	bool flag=true;
	for(int i=1;i<n;i++)
		if(a[i]>a[i+1])
			flag=false;
	if(flag){
		for(int i=1;i<=n;i++)
			if(i==n||a[i]!=a[i+1])
				ans[a[i]]+=i;
		for(int i=1;i<=m;i++)
			cout<<ans[i]<<" ";
		return 0;
	}
	for(int i=1;i<=n;i++)
		if(i==n||a[i]!=a[i+1])
			ans[a[i]]+=i;
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<" ";
	return 0;
}
