#include <bits/stdc++.h>
using namespace std;
#define int long long
int c,t,n,d;
int a[2000010],dp[2000010],vis[2000010];
int num;
int mi=0x3f3f3f3f3f3f3f3f;
void dfs(int now,int end,int step){
	if(now==end){
//		for(int i=1;i<=n;++i){
//			cout<<vis[i]<<" ";
//		}
//		cout<<"\n";
		mi=min(mi,step);
		//++num;
		return;
	}
	int ret=0;
	for(int i=1;i<=n;++i){
		if(abs(a[i]-now)<=d&&a[i]-now!=0&&vis[a[i]]==0){
			vis[a[i]]=1;
			dfs(a[i],end,step+1);
			vis[a[i]]=0;
		}	
	}
}
void dfs2(int now,int end,int step){
	
	if(now==end){
		//cout<<1;
//		for(int i=1;i<=n;++i){
//			cout<<vis[i]<<" ";
//		}
//		cout<<"\n";
		//cout<<step<<" "<<mi<<"\n";
		if(step==mi)++num;
		//++num;
		return;
	}
	for(int i=1;i<=n;++i){
		//cout<<a[i]<<" "<<now<<"\n";
		if(abs(a[i]-now)<=d&&a[i]-now!=0&&vis[a[i]]==0){
			vis[a[i]]=1;
			dfs2(a[i],end,step+1);
			vis[a[i]]=0;
		}	
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;++i){
			cin>>a[i];
		}
		//cout<<n<<" "<<d<<"\n";
		int ans=0;
		for(int i=1;i<=n;++i){
			for(int j=i+1;j<=n;++j){
				num=0;
				if(i!=j){
					mi=0x3f3f3f3f3f3f3f3f;
					vis[a[i]]=1;
					dfs(a[i],a[j],0);
					memset(vis,0,sizeof vis);
					vis[a[i]]=1;
					dfs2(a[i],a[j],0);
					//cout<<i<<" "<<j<<" "<<num<<"\n";
					if(num==2)++ans;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
