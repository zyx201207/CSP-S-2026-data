#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005];
map<int,int> mp;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int k=1;k<=n;k++){
		queue<int> q;
		int vis[n+5];
		for(int i=1;i<=n;i++) vis[i]=0;
		for(int j=k;j<=n;j++){
			if(!vis[a[j]]){
				q.push(a[j]);
				vis[a[j]]=1;
			}
			else if(vis[a[j]]){
				while(!q.empty()) q.pop();
				for(int i=1;i<=n;i++) vis[i]=0;
				q.push(a[j]);
			}
		}
		while(!q.empty()){
			int x=q.front();
			q.pop();
			mp[x]++;
		}
		
	}
	
	for(auto it:mp) cout<<it.second<<" ";
	return 0;
}
