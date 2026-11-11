#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],vis[500005],fl1=1;
map<int,int>mp,ans;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1]&&i!=1){
			fl1=0;
		}
	}
	if(fl1){
		for(int i=1;i<=n;i++){
			if(a[i]!=a[i+1]){
				cout<<i<<" ";
			}
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		mp.clear();
		for(int j=i;j<=n;j++){
			if(mp[a[j]]){
				for(int k=j-1;k>=1;k--){
					if(vis[k]!=i){
						mp[a[k]]--;
						vis[k]=i;
					}
					if(a[k]==a[j]){
						break;
					}
				}
			}
			mp[a[j]]++;
		}
		for(auto j:mp){
			if(!j.second){
				continue;
			}
			ans[j.first]++;
		}
	}
	for(auto i:ans){
		cout<<i.second<<" ";
	}
	return 0;
}

