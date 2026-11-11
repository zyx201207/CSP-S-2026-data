#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,A=1;
int a[500005],cnt[500005],vis[500005],ans[500005],ke[500005];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
		if(a[i]<a[i-1])A=0;
		cnt[a[i]]=i;
	}
	if(A){
		for(int i = 1;i <= m;i++){
			if(cnt[i]==0)cout<<0<<" ";
			else cout<<cnt[i]<<" ";
		}
	}else if(m==2){
		int ans1=0,ans2=0;
		if(a[n]==1){
			ans1=n;
			for(int i = n-1;i >= 0;i--)if(a[i]==2)ans2++;
			cout<<ans1<<" "<<ans2;
		}
		else{
			ans2=n;
			for(int i = n-1;i >= 0;i--)if(a[i]==1)ans1++;
			cout<<ans1<<" "<<ans2;
		}
	}else{
		for(int i = 1;i <= n;i++){
			memset(vis,0,sizeof vis);
			memset(ke,1,sizeof ke);
			for(int j = i;j <= n;j++){
				if(vis[a[j]]){
					int num;
					for(int k = j-1;a[k]!=a[j];k--){
						if(ke[k])vis[a[k]]--,ke[k]=0;
						num=k-1;
					}
					ke[num]=0;
				}else vis[a[j]]++;
			}
			for(int j = 1;j <= m;j++){
				if(vis[j])ans[j]++;
			}
		}
		for(int i = 1;i <= m;i++)cout<<ans[i]<<" ";
	}
	return 0;
}
/*
10 3
3 1 2 1 3 2 3 1 2 1
*/