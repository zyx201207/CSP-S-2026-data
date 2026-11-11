#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pll pair<ll,ll>
#define fi first
#define se second
ll maxn=-1;
ll n,m,a[200005];
ll vis[200005];
void dfs(ll le,ll now){
	if(le==m+1){
		maxn=max(now,maxn);
	}
	else{
		for(int i=1;i<=n;i++){
			if(!vis[i]&&(now&a[i])>now){
				vis[i]=1;
				dfs(le+1,(now&a[i]));
				vis[i]=0;
			}
			
		}
	}
} 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)dfs(1,a[i]);
	cout<<maxn;
	return 0;
} 
