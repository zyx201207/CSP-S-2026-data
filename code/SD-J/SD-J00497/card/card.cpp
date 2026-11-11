#include<bits/stdc++.h>

using namespace std;

int n,m;
int a[500005];
map<int,int>ans;
int cnt;

signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<n;i++)if(a[i]<=a[i+1])cnt++;
	if(cnt==n-1){
		//cout<<1<<'\n';
		for(int i=1;i<=n;i++){
			for(int j=i;j<n;j++){
				//cout<<a[j]<<' '<<a[j+1]<<' ';
				if(a[j]!=a[j+1])ans[a[j]]++;
				//cout<<ans[a[j]]<<'\n';
			}
			if(a[n-1]!=a[n])ans[a[n]]++;
		}
	}
	else for(int i=1;i<=n;i++){
		map<int,int>mp;
		for(int j=i;j<=n;j++){
			//cout<<mp[a[j]]<<'\n';
			if(!mp[a[j]])mp[a[j]]=j;
			else{
				for(int k=mp[a[j]];k<j;k++){
					mp.erase(a[k]);
				}
				mp[a[j]]=j;
			}
		}
		for(auto j:mp){
			//cout<<j.first<<' ';
			ans[j.first]++;
		}
		//puts("");
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
	return 0;
}

