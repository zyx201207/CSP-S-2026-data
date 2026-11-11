#include <bits/stdc++.h>
using namespace std;
const int N=5010;
int a[N],last[N];
int cnt[N];
int n,m;
void solve(int s){
    memset(last,0,sizeof(last));
    for(int i=s;i<=n;i++){
        if(last[a[i]]==0) last[a[i]]=i;
        else{
            for(int j=last[a[i]];j<=i;j++) last[a[j]]=0;
            last[a[i]]=i;
        }
    }
    for(int i=1;i<=m;i++){
        if(last[i]!=0) cnt[i]++;
    }
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        solve(i);
    }
    for(int i=1;i<=m;i++) cout<<cnt[i]<<" ";
    return 0;
}
