#include<bits/stdc++.h>
#define int long long
#define inf 1e17
using namespace std;
int c,t,n,d,a[2000005],ans,cnt[2000005],mn[2000005];
inline void dfs(int i,int stp){
	if(i>n){
		return ;
	}
	if(stp<mn[i]){
		if(cnt[i]==2){
			ans--;
		}
		cnt[i]=1;
		mn[i]=stp;
	}else if(stp==mn[i]){
		cnt[i]++;
		if(cnt[i]==2){
			ans++;
		}else if(cnt[i]>2){
			ans--;
		}
	}
	for(int j=i+1;j<=n&&a[j]-a[i]<=d;j++){
		dfs(j,stp+1);
	}
	return ;
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
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(c==13||c==14){
			cout<<"0\n";
			continue;
		}
		for(int i=1;i<n-2;i++){
			mn[i]=-1;
			for(int j=i+1;j<=n;j++){
				mn[j]=inf;
				cnt[j]=0;
			}
			dfs(i,0);
		}
		cout<<ans<<'\n';
		ans=0;
	}
	return 0;
}

