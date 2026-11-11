#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int n,m;
int ans[N];
map<int,int> mp;
int a[N];
vector<int> col[N];
int nxt[N];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	memset(nxt,-1,sizeof(nxt));
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		//memset(vis,0,sizeof(vis));
		
		for(auto &p:mp){
			p.second=0;
		}
		for(int j=i;j<=n;j++){
			if(mp[a[j]]==1){
				int p=col[a[j]].back();
				for(int k=p;k<j;k++){
					mp[a[k]]--;
					//col[a[j]].clear();
				}
			}
			col[a[j]].push_back(j);
			mp[a[j]]++;
		}
		for(auto &p:mp){
			if(p.second>=1){
				ans[p.first]++;
			}
		}
		//for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
		//cout<<"\n";
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
