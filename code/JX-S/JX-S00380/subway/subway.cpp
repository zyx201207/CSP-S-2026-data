#include<bits/stdc++.h>
using namespace std;
const int N1=500005,N2=100005;
#define ll long long
int c,n,m,d,q,w[N1];
int x[N2],y[N2];
ll f[505][505];
vector<pair<int,int> >t[N1];
ll read(){
    ll x=0ll;
    char c=getchar();
    while(c<'0'||c>'9')c=getchar();
    while(c>='0'&&c<='9'){
        x=x*10ll+c-'0';
        c=getchar();
    }
    return x;
}
void wt(ll x){
    if(x<=9)putchar(x+'0');
    else{
        wt(x/10);
        putchar(x%10+'0');
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    c=read();n=read();m=read();
    d=read();q=read();
    for(int i=1;i<=m;i++)w[i]=read();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            f[i][j]=1e18;
        }
    }
    for(int i=1;i<=n;i++){
        f[i][i]=0ll;
        int k;
        k=read();
        for(int j=1;j<=k;j++){
            int a,t1;
            a=read();t1=read();
            t[a].push_back({i,t1});
        }
    }
    for(int i=1;i<=q;i++){
        x[i]=read();y[i]=read();
    }
    for(int i=1;i<=m;i++){
        for(auto j1:t[i]){
            for(auto j2:t[i]){
                int k1=j1.first,t1=j1.second;
                int k2=j2.first,t2=j2.second;
                f[k1][k2]=min(f[k1][k2],1ll*(t1+t2));
                f[k2][k1]=f[k1][k2];
            }
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
                f[j][i]=f[i][j];
            }
        }
    }
    for(int i=1;i<=q;i++){
        ll num=1e18;
        for(auto j1:t[x[i]]){
            for(auto j2:t[y[i]]){
                int k1=j1.first,t1=j1.second;
                int k2=j2.first,t2=j2.second;
                ll k=w[x[i]]+w[y[i]];
                k+=t1;
                k+=t2;
                k+=f[k1][k2];
                num=min(num,k);
            }
        }
        wt(num);
        putchar('\n');
    }
}