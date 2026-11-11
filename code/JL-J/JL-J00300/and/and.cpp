#include<bits/stdc++.h>
using namespace std;

const int N=2*1e3+10;
int n,m;
int a[N];
int cnt[N];
bool f[N];
int ans;

void print(){
    int t=a[cnt[1]];
    for(int i=2;i<=m;i++){
        t=t&a[cnt[i]];
    }
    ans=max(ans,t);
}

void dfs(int k){
    if(k<=m){
        for(int i=1;i<=n;i++){
            if(f[i]==false){
                cnt[k]=i;
                f[i]=true;

                if(k==m) print();
                else dfs(k+1);

                f[i]=false;
            }
        }
    }
}

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }

    dfs(1);

    cout<<ans;
    return 0;
}
