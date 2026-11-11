#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ri register int
using namespace std;
const int N=5e5+5;
int n;
ll m,a[N],pre[N],l[2][N];
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;

    bool spA=1,spB=1,spS=1;

    for(ri i=1;i<=n;++i)cin>>a[i];
    sort(a+1,a+1+n);
    //spS
    if(a[1]>=-100&&a[n]<=100&&n>5000){
        ll mx=a[n],cnt;
        for(ri i=1;i<=n;++i){
            cnt+=(mx-a[i]);
        }
        if(cnt<=m){
            cout<<n;
            return 0;
        }
    }
    //spA
    for(ri i=1;i<=n;++i)if(a[i]!=i){spA=0;break;}
    if(spA){
        ll ans=0;
        for(ri i=1;i<=n;++i){
            ans=ans+i;
            if(ans>m){
                ans=i;
                cout<<i;
                return 0;
            }
        }
    }
    //spB-
    for(ri i=2;i<=n;++i)pre[i]=a[i]-a[i-1];
    //spB
    for(ri i=3;i<=n;++i)if(pre[i]!=pre[i-1]){spB=0;break;}
    if(spB){
        ll ans=0;
        int cha=pre[2];
        for(ri i=1;i<=n;++i){
            ans=ans+(i*cha);
            if(ans>=m){
                ans=i;
                cout<<i;
                return 0;
            }
        }
    }
    
    int p=1,lp=0;
    ll ans=n;
    for(ri i=1;i<=n-1;++i){
        l[lp][i]=pre[i+1];
    }
    for(ri i=2;i<=n-1;++i){
        ll mn=1e18;
        for(ri j=1;j<=n-i;++j){
            l[p][j]=pre[i+j]*i+l[lp][j];
            mn=min(mn,l[p][j]);
        }
        if(mn>m){
            ans=i;
            break;
        }
        swap(p,lp);
    }
    cout<<ans;


    return 0;
}