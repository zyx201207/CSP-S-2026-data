#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200001];
int ans=0;
void solve(int last,int cnt,int andsum){
     if(cnt==m){
        ans=max(ans,andsum);

        return;
    }
    if(last>n){
        return;
    }

    for(int i=last;i<=n;i++){

        solve(i+1,cnt+1,andsum&a[i]);
    }
    return;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    solve(1,0,INT_MAX);
    cout<<ans;
    return 0;
}
