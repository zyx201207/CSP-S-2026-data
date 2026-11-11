#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
ll a[N];
int bitcnt[40];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    int len=n;
    for(int j=29;j>=0;j--){
        /*for(int i=1;i<=n;i++){
            printf("%lld ",a[i]);
        }puts("");*/
        //printf("%d\n",j);
        int l=1,r=len;
        bool is1=1,is0=1;
        for(int i=1;i<=n;i++){
            if(a[i]&(1LL<<j)) is0=0;
            else is1=0;
        }
        if(is0||is1)continue;
        while(l<=r){
            while(a[l]&(1LL<<j))l++;
            while(!(a[r]&(1LL<<j)))r--;
            if(l<r){
                ll tmp=a[l];a[l]=a[r];a[r]=tmp;
                l++,r--;
            }
        }
        if(r<m){
            continue;
        }else{
            len=r;
        }
    }
    ll ans=a[1];
    for(int i=1;i<=m;i++){
        ans&=a[i];
    }
    printf("%lld\n",ans);
    return 0;
}
