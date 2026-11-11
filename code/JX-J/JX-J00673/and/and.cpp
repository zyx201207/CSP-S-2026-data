#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005]={0};
long long Max=INT_MIN;
long long all=0;
void dfs(int k,long long now){
    if(k==m){
        Max=max(Max,now);
        return;
    }
    for(int i=k+1;i<=n;i++){
        dfs(i,(now&a[i]));
    }
    return;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        Max=max(Max,a[i]);
    }
    if(m==1){
        cout<<Max;
        return 0;
    }else if(m==n){
        all=a[1];
        for(int i=2;i<=n;i++)
            all&=a[i];
        cout<<all;
        return 0;
    }
    Max=INT_MIN;
    sort(a+1,a+1+n);
    dfs(0,INT_MAX);
    cout<<Max;
    return 0;
}
