#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+7;
int a[N];
int cf[N];
void solve(){
    int n,d;cin >>n>>d;
    for(int i=1;i<=n;i++){
        cin >>a[i];
        if(i!=1)cf[i]=a[i]-a[i-1];
    }
    bool fa=1;
    for(int i=3;i<=n;i++){
        if(cf[i]!=cf[i-1])fa=0;
    }
    if(fa){
        if(d==1){
            cout<<0<<endl;
            return;
        }
        // int t=d/cf[2];
        int ans=0;
        // for(int i=1;i<=(n-1)/t;i++){
        //     //i*t+1~(i+1)*t
        //     ans+=1;
        // }
        for(int i=1;i<=(n-1)/d;i++){
            ans+=n-(i*d+1);
        }
        cout<<ans<<"\n";
        // int tt=(n-1)/(d+1);
        // if(t==0)cout<<0<<endl;
        // else 
        // cout<<tt*(n%(d+1))<<endl;
        return;
    }
    // for(int i=1;i<=n;i++){
    //     for(int j=i+1;j<=n;j++){
    //         int s=0,cnt=0;
    //         for(int k=i+1;k<=j;k++){    //             if(s+cf[k]<=d){
    //                 s+=cf[k];
    //             }else{
    //                 cnt++;
    //                 s=0;
    //             }
    //         }
    //         if(s)cnt++;
    //     }
    // }
}
signed main(){
    freopen("migrate4.in","r",stdin);
    // freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int c,t;cin >>c>>t;
    while(t--)solve();
    return 0;
}
/*
0 3
4 2
1 2 3 4
5 2
1 2 3 4 5
5 3
-2 -1 0 1 2
*/