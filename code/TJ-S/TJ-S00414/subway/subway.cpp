#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll INF=1000000000000000009;
ll read(){
    ll ans=0;
    char c;
    c=getchar_unlocked();
    while(c<'0'||c>'9')c=getchar_unlocked();
    while(c>='0'&&c<='9')ans=ans*10+(c-'0'),c=getchar_unlocked();
    return ans;
}
ll ma[500005][23]={},t[500005][23]={};
    ll w[500005]={},cnt[500005]={};
    ll d[505][505]={};
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ll c,n,m,D,q;
    c=read(),n=read(),m=read(),D=read(),q=read();
    for(int i=1;i<=m;i++)w[i]=read();
    for(int i=0;i<n;i++){
        ll k=read();
        for(int j=0;j<k;j++){
            ll a;
            a=read();
            ma[a][cnt[a]]=i;
            t[a][cnt[a]++]=read();
        }
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            if(i==j)d[i][j]=0;
            else d[i][j]=INF;
        }
    }
    for(int i=1;i<=m;i++){
        for(int j1=0;j1<cnt[i];j1++){
            for(int k1=j1+1;k1<cnt[i];k1++){
                ll j=ma[i][j1],k=ma[i][k1];
                d[k][j]=min(d[k][j],t[i][j1]+t[i][k1]);
                d[j][k]=min(d[j][k],t[i][j1]+t[i][k1]);
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j)continue;
            for(int k=0;k<n;k++){
                if(i==k)continue;
                d[j][k]=min(d[j][k],d[i][j]+d[i][k]);
            }
        }
    }
    while(q--){
        ll x,y;
        x=read(),y=read();
        ll ans=INF;
        for(int i=0;i<cnt[x];i++){
            for(int j=0;j<cnt[y];j++){
                ans=min(ans,d[ma[x][i]][ma[y][j]]+t[x][i]+t[y][j]);
            }
        }
        cout << ans+w[x]+w[y] << '\n';
    }
    return 0;
}