#include<bits/stdc++.h>
using namespace std;
long long a[200010];
long long n,m,maxn=-1e9;
void dfs(long long x,long long y,long long ma){
    if(y<=0){
        cout<<ma;
        return ;
    }
    if(ma==-1e9){
        long long p,q;
        for(long long i=x;i<=n;i++){
            for(long long j=i+1;j<=n;j++){
                if(a[i]&a[j]>ma){
                    p=i;q=j;
                }
                ma=max(ma,a[i]&a[j]);
            }
        }
        a[p]=-1;a[q]=-1;y-=1;
    }
    else{
        long long w=ma,k=0;
        for(long long i=1;i<=n;i++){
            if(a[i]!=-1){
                if(w&a[i]>w) k=i;
                w=max(w,w&i);
            }
        }
        ma=max(w,ma);
        a[k]=-1;
    }
    dfs(x+1,y-1,ma);
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    dfs(1,m,maxn);
    return 0;
}
