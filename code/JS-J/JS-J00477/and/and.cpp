#include<bits/stdc++.h>
using namespace std;

const int N=2e5+1,inf=2<<20-1;
long long n,m,a[N],ans=-1;
bool used[N];

void dfs(int k,int me,long long now){
    if(me==m)dfs(k+1,i,now);
    else if(k>n){
        if(me==m){
            if(ans<now)ans=now;
        }
        return;
    }
    else if(me==0){
        for(int i=1;i<=n;++i){
            used[a[i]]=1;
            dfs(k+1,i+1,a[i]);
            dfs(k+1,i,now);
            used[a[i]]=0;
        }
    }else{
        for(int i=1;i<=n;++i){
            if(used[a[i]])continue;
            used[i]=1;
            dfs(k+1,i+1,now&a[i]);
            dfs(k+1,i,now);
            used[i]=0;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;++i){
        cin >> a[i];
    }
    dfs(1,0,0);
    cout << ans<<endl;
}
