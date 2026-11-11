#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;
int n,m;
ll ans;
ll memo[N];
int a[N];
unordered_map<int,bool> vis;
void dfs(int d,ll sum){
    if(d==m+1){
        ans=max(ans,sum);
        return ;
    }
    for(int i=1;i<=n;i++){
        if(!vis[a[i]]){
            vis[a[i]]=true;
            dfs(d+1,sum&a[i]);
            vis[a[i]]=false;
        }
    }
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
        cin>>a[i];
	}
	dfs(1,(1<<30)-1);
	cout<<ans<<"\n";
	return 0;
}

