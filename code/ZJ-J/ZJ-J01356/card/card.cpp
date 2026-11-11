#include<bits/stdc++.h>
using namespace std;
//using LL=long long;
#define fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
//#define endl '\n'
const int N=5e5+10,M=3e5+10;
int n,m;
int a[N];
bool fa[M];
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	set<int>cnt[m+1];
	vector<int>dis(m+10,0);
	for(int i=n;i>=1;i--){
		int d=a[i];
		if(!fa[d]){
			fa[d]=1;
			cnt[d]=cnt[a[i+1]];
			cnt[d].insert(d);
		}
		for(auto j:cnt[d])++dis[j];
	}
	for(int i=1;i<=m;i++)cout<<dis[i]<<" ";
	return;
}
int main(){
	fast;
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	solve();
	return 0;
}
