#include<bits/stdc++.h>
using namespace std;
int n,m,idx=0;
int a[550000];
int num[550000],cnt[550000],nxt[550000],lz[550000];
vector<int>pre[550000];
int to[550000];
int nl[330000];
int ans[330000];
bool vis[550000];
void dfs(int now){
    for(auto x:pre[now]){
        dfs(x);
        cnt[now]+=lz[x];
        lz[now]+=lz[x];
    }
    ans[num[now]]+=cnt[now];
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=n;i>=1;i--){
        if(nl[a[i]]!=0){
            to[i]=to[nl[a[i]]];
            cnt[to[i]]++;
            lz[to[i]]++;
            continue;
        }
        num[++idx]=a[i];
        if(i<n) pre[to[i+1]].push_back(idx);
        cnt[idx]++;
        lz[idx]++;
        nl[a[i]]=i;
        to[i]=idx;
	}
	dfs(to[n]);
	for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
	return 0;
}
