#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
#define int long long
int n,m,cnt,maxx=0;
int a[N];
int to[N];
int pd(){
    int ma=0;
    for(int i=1;i<=cnt;i++){
        ma=max(ma,to[i]);
    }
    return ma;
}
void dfs(int x,int y){
    if(y==m){
        maxx=max(maxx,pd());
        return;
    }
    if(x==n+1) return;
    for(int i=0;i<=m-y;i++){
        to[a[x]]--;
        to[a[x]+i]++;
        dfs(x+1,y+i);
        to[a[x]]++;
        to[a[x]+i]--;
    }
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        to[a[i]]++;
    }
    sort(a+1,a+n+1);
    cnt=a[n];
    dfs(1,0);
    cout<<maxx;
    return 0;
}
