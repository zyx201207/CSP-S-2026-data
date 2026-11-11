#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e6+10;
int L[maxn],R[maxn];
int pre[maxn],suf[maxn];
int buc[maxn];
ll a[maxn];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    scanf("%d%d",&c,&t);
    while(t--){
        int n;
        ll d;
        scanf("%d%lld",&n,&d);
        for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
        L[1]=1,R[n]=n;
        for(int l=1,r=1;l<=n;l++){
            while(r+1<=n&&a[r+1]-a[l]<=d){
                if(r+1>=l)L[r+1]=l;
                r++;
            }
            R[l]=r;
        }
        for(int i=1;i<n;i++){
            pre[i]=((R[L[L[i]]]==L[i])?pre[L[i]]:0)+L[i+1]-L[i];
        }
        for(int i=n;i>1;i--){
            suf[i]=((L[R[R[i]]]==R[i])?suf[R[i]]:0)+R[i]-R[i-1];
        }
        // for(int i=1;i<=n;i++){
        //     cerr<<L[i]<<' ';
        // }
        // cerr<<'\n';
        // for(int i=1;i<=n;i++){
        //     cerr<<R[i]<<' ';
        // }
        // cerr<<'\n';
        // for(int i=1;i<=n;i++){
        //     cerr<<pre[i]<<' ';
        // }
        // cerr<<'\n';
        // for(int i=1;i<=n;i++){
        //     cerr<<suf[i]<<' ';
        // }
        // cerr<<'\n';
        ll res=0;
        for(int i=2;i<n;i++){
            if(R[L[i+1]]==i+1&&L[R[i]]==i&&R[i]>i+1&&L[i+1]<i){
                res+=1ll*pre[i+1]*suf[i];
                // cerr<<i<<' '<<i+1<<'\n';
                // cerr<<1ll*pre[i+1]*suf[i]<<'\n';
            }
        }
        printf("%lld\n",res);
        for(int i=1;i<=n;i++){
            L[i]=R[i]=pre[i]=suf[i]=buc[i]=0;
        }
    }
    return 0;
}

/*

10 3
0 3 6 7 8 9 10 13 16 19
*/