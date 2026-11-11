#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+10;
ll n,m,a[N],ans=0;
ll t[40],idx[40][N];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        ll num=a[i];
        for(ll j=0;j<=31;j++){
            if(num&(1<<j)){
                t[j]++;
                idx[j][t[j]]=a[i];
            }
        }
    }
    //for(int i=0;i<=31;i++){
    //    cout<<t[i]<<" ";
    //}
    //cout<<'\n';
    for(ll j=31;j>=0;j--){
        if(t[j]>=m){
            //for(int i=1;i<=n;i++){
            //    cout<<a[i]<<" ";
            //}
            //cout<<'\n';
            n=t[j];
            for(int k=31;k>=0;k--)t[k]=0;
            ans+=(1<<j);
            for(int i=1;i<=n;i++){
                a[i]=idx[j][i];
            }
            for(int i=1;i<=n;i++){
                ll num=a[i];
                for(ll k=0;k<=31;k++){
                    if(num&(1<<k)){
                        t[k]++;
                        idx[k][t[k]]=a[i];
                    }
                }
            }
        }
    }
    cout<<ans;
    return 0;
}
