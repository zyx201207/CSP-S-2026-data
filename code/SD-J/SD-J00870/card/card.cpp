#include<bits/stdc++.h>//powered_by_flyin2899
#define int unsigned long long//need to fix:TLE
using namespace std;

int n,m,a[500005],res[300005];
vector<int>q;
unordered_map<int,int>mp;

signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int cur=0;
		q.push_back(0);
		for(int j=i;j<=n;j++){
			if(mp[a[j]]==0){
				mp[a[j]]=++cur;
				q.push_back(a[j]);
			}else{
				for(int k=cur;k>mp[a[j]];k--){
					mp[q[k]]=0;
					q.pop_back();
				}
				cur=mp[a[j]];
			}
		}
		for(auto tmp:mp){
			if(tmp.second!=0){
				res[tmp.first]++;
			}
		}
		q.clear();
		mp.clear();
	}
	for(int i=1;i<=m;i++){
		cout<<res[i]<<' ';
	}
	return 0;
}
