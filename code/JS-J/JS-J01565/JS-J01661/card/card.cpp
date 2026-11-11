#include <bits/stdc++.h>
#define ll long long
using namespace std;
inline ll read(){
    ll x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-') f=-1;
        ch=getchar();
    }while(ch>='0'&&ch<='9'){
        x=x*10+(ch-48);
        ch=getchar();
    }
    return x*f;
}
ll n,m;
ll a[500005];
ll w[500005];
bool vis[500005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    n=read();
    m=read();
    for(int i = 1;i<=n;i++){
        a[i]=read();
    }
    for(int i = 1;i<=m;i++){
        ll cntt=0;
        for(int j = i;j<=n;j++){
            if(vis[a[j]]==0){
                w[cntt++]=a[j];
                a[j]=1;
            }
        }
    }
    for(int i =1;i<=n;i++){
        cout<<a[i]<<' ';
    }
    return 0;
}
