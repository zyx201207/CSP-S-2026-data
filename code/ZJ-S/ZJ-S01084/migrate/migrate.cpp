#include<bits/stdc++.h>
#define For(i,j,k) for(auto i=(j);i<=(k);i++)
#define dFor(i,j,k) for(auto i=(j);i>=(k);i--)
using namespace std;
#define MAXN 2000005
int n;
long long d,x[MAXN];
int nxt[MAXN];
long long f[MAXN][3],g[MAXN];
inline void add(int l,int r,long long k){
    if(l>r) return ;
    g[l]+=k;
    g[r+1]-=k;
}
void solve(){
    cin>>n>>d;
    For(i,1,n){
        cin>>x[i];
        f[i][0]=f[i][1]=f[i][2]=0;
        g[i]=0;
    }
    int pos=1;
    For(i,1,n){
        while(pos+1<=n&&x[pos+1]-x[i]<=d){
            pos++;
        }
        nxt[i]=pos;
    }
    long long ans=0;
    For(i,1,n){
        g[i]+=g[i-1];
        ans+=g[i];
        if(nxt[i]==i){
            continue ;
        }
        f[nxt[i]][0]++;
        if(i>=3&&x[nxt[i]]-x[i-1]<=d){
            if(x[nxt[i]]-x[i-2]>d){
                f[nxt[i]][1]+=f[i][0];
            }
        }else{
            if(i>=2&&x[nxt[i]-1]-x[i-1]<=d){
                f[nxt[i]][2]+=f[i][0]+f[i][2];
                f[nxt[i]][1]+=f[i][1];
            }else{
                f[nxt[i]][0]+=f[i][0]+f[i][2];
                f[nxt[i]][1]+=f[i][1];
            }
        }
        if(nxt[i-1]==i-1){
            continue ;
        }
        int l=upper_bound(x+1,x+n+1,d+x[i-2])-x;
        int r=upper_bound(x+1,x+n+1,d+x[i-1])-x-1;
        add(max(l,i+1),r,f[i][0]);
        add(r+1,nxt[i],f[i][1]);
    }
    cout<<ans<<'\n';
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int c,T;
    cin>>c>>T;
    while(T--){
        solve();
    }
    return 0;
}
/*
g++ -O2 -std=c++14 -Wall -Wextra -Wshadow -o migrate migrate.cpp
0 1
10 3
0 3 6 7 8 9 10 11 14 17
*/