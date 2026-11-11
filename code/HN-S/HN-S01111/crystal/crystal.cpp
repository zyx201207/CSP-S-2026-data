#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
typedef long long ll;
typedef __int128 i128;
ll a[N];i128 f[N];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n;ll m;cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=2;i<=n;i++)
        f[i]=f[i-1]+i128(i-1)*(a[i]-a[i-1]);
    int mx=1;
    auto get=[&](int l,int r){return f[r]-f[l]-i128(l-1)*(a[r]-a[l]);};
    for(int i=2;i<=n;i++){
        int mid,l=1,r=i;
        while(l<=r){
            int mid=l+r>>1;
            if(get(mid,i) > m) l=mid+1;
            else r=mid-1;
        }
        // ans: l
        mx=max(mx,i-l+1);
    }
    cout<<mx<<'\n';
    return 0;
}


// #include<bits/stdc++.h>
// using namespace std;
// const int N=5e5+10;
// typedef long long ll;
// typedef __int128 i128;
// ll a[N];i128 f[N];
// int main(){
//     ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
//     // freopen("crystal.in","r",stdin);
//     // freopen("crystal.out","w",stdout);
//     int n;ll m;cin>>n>>m;
//     for(int i=1;i<=n;i++) cin>>a[i];
//     sort(a+1,a+n+1);
//     int mxd=0;
//     for(int i=2;i<=n;i++){
//         f[i]=f[i-1]+i128(i-1)*(a[i]-a[i-1]);
//         mxd=max(mxd,(int)log2((double)f[i]));
//     }
//     int mx=1;
//     auto get=[&](int l,int r){return f[r]-f[l]-i128(l-1)*(a[r]-a[l]);};
//     for(int i=2;i<=n;i++){
//         int mid,l=1,r=i;
//         while(l<=r){
//             int mid=l+r>>1;
//             if(get(mid,i) > m) l=mid+1;
//             else r=mid-1;
//             mxd=max(mxd,(int)log2((double)get(mid,i)));
//         }
//         // ans: l
//         mx=max(mx,i-l+1);
//     }
//     cout<<mxd<<'\n';
//     cout<<mx<<'\n';
//     return 0;
// }




