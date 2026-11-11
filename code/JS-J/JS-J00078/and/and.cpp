#include<bits/stdc++.h>
using namespace std;
const int N=2e5+16;
int cnt[32],c[32];
struct node{
    int v,h;
}a[N];
bitset<32>f[N];
bitset<N>vis;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m,ans=0,k=0;
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        cin>>a[i].v;
        for(int j=30;~j;--j){
            if(a[i].v>>j&1){
                ++cnt[j];
                if(!a[i].h){
                    a[i].h=j;
                }
            }
        }
    }
    sort(a+1,a+1+n,[](const node &x,const node &y){
        if(x.h^y.h){
            return x.h>y.h;
        }
        return x.v>y.v;
    });
    for(int i=1;i<=n;++i){
        for(int j=30;~j;--j){
            f[i][j]=(a[i].v>>j&1);
        }
    }
    for(int j=30;~j;--j){
        if(cnt[j]>=m){
            for(int i=1;i<=n;++i){
                if(f[i][j]){
                    if(!vis[i]&&k<m){
                        ++k;
                        vis[i]=1;
                    }
                    if(vis[i]){
                        ++c[j];
                    }
                }
            }
        }
    }
    for(int j=30;~j;--j){
        if(c[j]==m){
            ans+=1<<j;
        }
    }
    cout<<ans;
    return 0;
}