#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
const int N=5e3+5;
int a[N];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	vector<map<int,pair<int,bool>>> mp(n+1);
	for(int i=1;i<=n;i++){//¾Ö 
		mp[i][a[i]]={i,1};
		for(int j=i+1;j<=n;j++){
			if(mp[i][a[j]].second==true){
				int wei=mp[i][a[j]].first;
				for(int k=wei;k<=j;k++) mp[i][a[k]].second=0;
				mp[i][a[j]]={j,1};
			}
			else mp[i][a[j]]={j,1};
		}
	}
	for(int i=1;i<=m;i++){
		int ans=0;
		for(int j=1;j<=n;j++){
			if(mp[j][i].second==1) ans++;
		}
		cout<<ans<<" ";
	}
	return 0;
}
