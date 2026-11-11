#include<bits/stdc++.h>
using namespace std;
int n,m;
long long maxn=0;
int a[200005];
void dfs(int x,int sum,long long ans){
    if(sum==m){
        maxn=max(ans,maxn);
        return;
    }
    if(maxn>ans)
        return;
    for(int i=x+1;i<=n;i++){
        if(sum==0)
            dfs(i,sum+1,a[i]);
        else
            dfs(i,sum+1,ans&a[i]);
    }
}
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(i==1)
            maxn=a[i];
        maxn&=a[i];
    }
    sort(a+1,a+n+1,cmp);
    if(m==1)
        cout<<a[1];
    else if(m==n){
        cout<<maxn;
    }
    else{
        maxn=0;
        dfs(0,0,0);
        cout<<maxn<<endl;
    }
}
