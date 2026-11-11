#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
bool f[200005];
int maxx=-1;
//final
void dfs(int num,int cnt,int ans) {
    //cout<<num<<" "<<cnt<<endl;
    f[num]=true;
    if (cnt==m) {
        maxx=max(maxx,ans);
        return;
    }
    for (int i=1;i<=n;i++) {
        if (f[i]==false) {
            dfs(i,cnt+1,ans&a[i]);
            f[i]=false;
        }
    }
    return;
}
int main () {
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
    }
    for (int i=1;i<=n;i++) {
        dfs(i,1,a[i]);
    }
    cout<<maxx;
    return 0;
}
