#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int a[N],cnt[N],vis[N];
queue<int> q[N];
int n,m;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		q[a[i]].push(i);
	}
	for(int i=1;i<=n;i++){
		for(int j=q[a[i]].back();j<=n;j++){
			cnt[a[j]]++;
			if(q[a[j]].back()>j){
				j=q[a[j]].back();
				continue;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<' ';
	}
	return 0;
}
