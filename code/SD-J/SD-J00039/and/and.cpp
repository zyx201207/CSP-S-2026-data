#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[200005],anss;
set<int>st[35],ans;
queue<int>q;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i],ans.insert(i);
	for(int i=0;i<=30;i++){
		for(int j=1;j<=n;j++){
			if((a[j]>>i)&1ll)st[i].insert(j);
		}
	}
	for(int i=30;i>=0;i--){
		anss+=(1ll<<i);
		if(st[i].empty())continue;
		for(int u:ans){
			if(!st[i].count(u))q.push(u);
		}
		if(q.empty())continue;
		if((int)ans.size()-(int)q.size()>=m){
			while(!q.empty())ans.erase(q.front()),q.pop();
		}
		while(!q.empty())q.pop();
	}
	for(int u:ans)anss&=a[u];
	cout<<anss<<"\n";
	return 0;
}
/*
4 2
3 15 12 12

5 3
31 3 1 15 7
*/
