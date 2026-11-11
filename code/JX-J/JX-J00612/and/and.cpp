#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+7;
int n,m;
int vis[N];
int a[N];
int sum;
int maxs;
void dfs(int x){
    if(x==m+1){
        bool flag=false;
        for(int i=1;i<=m;i++){
            if(!flag){
                sum=vis[a[i]];
                flag=true;
            }
            sum&=vis[a[i]];
        }
        maxs=max(maxs,sum);
        return;
    }
    for(int i=a[x-1]+1;i<=n;i++){
            a[x]=i;
            dfs(x+1);
    }
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
        cin>>vis[i];
     dfs(1);
     cout<<maxs;
	return 0;
}
