#include<bits/stdc++.h>
using namespace std;
long long a[200001],ans,ma;
int n,m;
void dfs(int i,int x){
    if(x==m){
        ans=max(ans,ma);
        return;
    }
    if(i>n||ma<=ans){
        return;
    }
    if(x==0){
        ma=a[i];
        dfs(i+1,x+1);
        ma=0;
        dfs(i+1,x);
        return;
    }
    i++;
    int v=ma;
    ma=v&a[i];
    dfs(i+1,x+1);
    ma=v;
    dfs(i+1,x);
    return;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    cout<<a[n];
}
