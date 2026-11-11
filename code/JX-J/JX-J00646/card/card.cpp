#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
const int M=3e5+5;
int n,m;
int a[N],last[M],match[N],ans[M];
bool covered[N],flag[M];
void solve(int s){
    for(int i=s;i<=n;i++)
        covered[i]=false;
    for(int i=1;i<=n;i++){
        if(match[i]<s||covered[match[i]])continue;
        for(int j=match[i];j<i;j++)
            covered[j]=true;
    }
    for(int i=1;i<=m;i++)
        flag[i]=false;
    for(int i=s;i<=n;i++)
        if(!covered[i]&&!flag[a[i]])
            ans[a[i]]++,flag[a[i]]=true;
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        match[i]=last[a[i]];
        last[a[i]]=i;
    }
    for(int i=1;i<=n;i++)
        solve(i);
    for(int i=1;i<=m;i++)
        cout<<ans[i]<<' ';
    return 0;
}
