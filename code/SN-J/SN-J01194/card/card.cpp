#include<bits/stdc++.h>
using namespace std;
const int N=5e5+1;
int a[N],cnt[N];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		bool vis[N]={};
		map<int,int> mp;
		for(int j=i;j<=n;j++){
			if(vis[a[j]]){
				for(int k=j;k>=mp[a[j]];k--){
					vis[a[k]]=0;
				}
				mp[a[j]]=j;
				vis[a[j]]=1;
			}else{
				vis[a[j]]=1;
				mp[a[j]]=j;
			}
		}
		for(int i=1;i<=m;i++){
			if(vis[i]) cnt[i]++;
//			cout<<vis[i]<<" ";
		}
//		cout<<endl;
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	
	
	
	return 0;
}
