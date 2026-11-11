#include<bits/stdc++.h>
#define int long long
using namespace std;
int opt,T,n,d,tot;
int a[2020202],b[2020202],ans[2020202],cnt[2020202];
void dfs(int level,int tans,int last){
	if(ans[level]==0){
		ans[level]=tans;
		cnt[level]=1;
	}
	else{
		if(ans[level]==tans)cnt[level]++;
		else{
			ans[level]=tans;
			cnt[level]=1;
		}
	}
	if(level==n)return;
	for(int i=b[last]+1;i<=b[level];i++){
		dfs(i,tans+1,level);
	}
	return;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>opt>>T;
	while(T--){
		cin>>n>>d;
		tot=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			b[i]=upper_bound(a+1,a+n+1,a[i]+d)-a-1;
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans[j]=0;
				cnt[j]=0;
			}
			dfs(i,0,i-1);
			for(int j=i+1;j<=n;j++){
				if(cnt[j]==2)tot++;
			}
		}
		cout<<tot<<'\n';
	}
	return 0;
}
