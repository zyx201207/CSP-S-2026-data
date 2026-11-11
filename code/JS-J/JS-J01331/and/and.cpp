#include <bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005],mx;
void dfs(long long s,int k,int f){
    if(k>m){
        mx=max(mx,s);
        return;
    }
    for(int i=f+1;i<=n;i++)
        dfs(s&a[i],k+1,i);
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n-m+1;i++)
        dfs(a[i],2,i);
    cout<<mx;
    return 0;
}
