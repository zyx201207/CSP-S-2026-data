//王彦龙 庆安初级中学 SN-J00629
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10,M=3e5+10;

int n,m;
int a[N];
int ans[M];
int vis[N];

signed main(){
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	cin>>n>>m;
	
	bool flaga=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1]) flaga=0;
	}
	
	if(flaga){
		for(int i=1;i<=n;i++){
			deque<int> q;
			for(int j=i+1;j<=n;j++){
				if(a[j]==a[j-1]) q.pop_back();
				q.push_back(j);
			}
			map<int,bool> mp;
			while(!q.empty()){
				if(!mp.count(a[q.front()])){
					ans[a[q.front()]]++;
					mp[a[q.front()]]=1;
				}
				q.pop_front();
			}
		}
		for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
		return 0;
	}
	
	for(int i=1;i<=n;i++){
		deque<int> q;
		for(int j=i;j<=n;j++){
			for(int r=j-1;r>=i;r--){
				if(a[r]==a[j]){
					for(int l=r;l<j;l++) q.pop_back();
				}
			}
			q.push_back(j);
		}
		map<int,bool> mp;
		while(!q.empty()){
			if(!mp.count(a[q.front()])){
				ans[a[q.front()]]++;
				mp[a[q.front()]]=1;
			}
			q.pop_front();
		}
	}
	
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	
	return 0;
	
}
