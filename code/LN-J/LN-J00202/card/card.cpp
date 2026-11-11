#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ri register int
using namespace std;
const int N=5e5+5;
const int M=3e5+5;
int n,m,a[N],t[M],rl[M];
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    bool ok1=0,ok2=0;
    for(ri i=1;i<=n;++i){
        cin>>a[i];
        if(a[i]<a[i-1])ok1=1;
    }
    if(!ok1){
        int ls=1;
        for(ri i=2;i<=n;++i){
            if(a[i]!=ls){
                t[ls]=i-1;
            }
            ls=a[i];
        }
        for(ri i=1;i<=n;++i)cout<<t[i]<<' ';
        return 0;
    }
    for(ri i=n;i>=1;--i){
        if(!rl[a[i]])rl[a[i]]=i;
    }
    // int llo[M];
    // for(ri i=1;i<=n;++i){
    //     memset(llo,0,sizeof(llo));
    //     for(ri j=rl[a[i]];j<=n;++j){
    //         if(llo[a[j]]){
    //             int tmp=llo[a[j]];
    //             for(ri z=1;z<=m;++z)if(llo[z]>tmp)llo[z]=0;
    //         }
    //         llo[a[j]]=j;
    //     }
    //     for(ri j=1;j<=m;++j)if(llo[j])++t[j];
    //     // for(ri j=1;j<=m;++j)cout<<llo[j]<<' ';
    //     // cout<<'\n';
    // }


    for(ri i=1;i<=n;++i){
        for(ri j=rl[a[i]];j<=n;){
            ++t[a[j]];
            ++j;
            if(j>n)break;
            if(rl[a[j]]!=j){
                j=rl[a[j]];
            }
        }
    }



    for(ri i=1;i<=m;++i)cout<<t[i]<<' ';
    return 0;
}
