#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ull=unsigned long long;
using db=double;
using ldb=long double;
ll n,m;
ll a[(ll)2e5];
ll zhi=0;
ll ma=0;
ll mi=4294967296;
ll ans=0;
// struct NODE{
//     ll cnt;
//     ll nus[(ll)1e5+1];
// };

//     NODE er[66];
// void baoli(ll s,ll nn,ll tans){
//     if(tans==0){
//         return ;
//     }
//     if(s>n){
//         return ;
//     }
//     if(nn==m){
//         ans=max(ans,tans);
//         return ;
//     }
//     baoli(s+1,nn+1,(nn!=1?tans&a[s]:a[s]));
//     baoli(s+1,nn,tans);
// }

bool vis[100];
void dfs(ll ncnt,ll tans){
    if(ncnt-1==m){
        ans=max(ans,tans);
        return ;
    }
    for(ll i=1;i<=n;++i){
        if(!vis[i]){
            vis[i]=1;
            dfs(ncnt+1,tans&a[i]);
            vis[i]=0;
        }
    }
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    // for(ll i=0;i<=65;++i){
    //     er[i].cnt=0;
    //     memset(er[i].nus,0,sizeof(er[i].nus));
    // }
    //Write Code HERE!!!!!!!!!
    cin>>n>>m;
    for(ll i=1;i<=n;++i){
        cin>>a[i];
        ll tmp=a[i]+1;
        
        if(!(tmp&a[i])){
            zhi++;
        }

        // ll co=a[i];
        // ll cnt=0;
        // while(co){
        //     cnt++;
        //     if(co%2==1){
        //         er[cnt].cnt++;
        //         er[cnt].nus[er[cnt].cnt]=a[i];
        //     }
        //     co=co>>1;
        // }

        ma=max(ma,a[i]);
        mi=min(mi,a[i]);
    }
    if(zhi==n){
        sort(a+1,a+1+n);
        cout<<a[n-m+1];
        return 0;
    }
    //sort(a+1,a+1+n,greater<ll>());
    
    dfs(1,2147483647ll);


    // for(ll i=32;i>=1;--i){
    //     if(er[i].cnt>=m){
    //         for(ll j=1;j<=er[i].cnt;++j){
    //             ll jj=er[i].nus[j];
    //             ll cnt=0;
    //             while(jj){
    //                 cnt++;
    //                 if(jj%2==0){
    //                     er[cnt].cnt=-1;
    //                 }
    //                 jj=jj>>1;
    //             }
    //         }
    //         ans+=(i<<1)/2;
    //     }
    // }
    cout<<ans<<"\n";
    

    return 0;
}
