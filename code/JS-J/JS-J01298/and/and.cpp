#include<bits/stdc++.h>
using namespace std;

long long n,k,a[1000005],maxn=INT_MIN;
void dfs(long long cnt,long long num,long long x){
    if(cnt>k){
        maxn=max(maxn,num);
        return;
    }
    for(int i=x+1;i<=n;i++){
        dfs(cnt+1,(num&a[i]),i);
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(k==1)maxn=max(a[i],maxn);
    }
    if(k==1){
        cout<<maxn;
        return 0;
    }
    for(int i=1;i<=n;i++){
        dfs(2,a[i],i);
    }
    cout<<maxn;
    return 0;
}
