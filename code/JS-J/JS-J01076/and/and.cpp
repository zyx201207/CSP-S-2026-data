#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n,m,a[N];
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%lld %lld",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",a+i);
    }
    int nw=n;
    for(int i=30;i>=0;i--){
        for(int j=1,k=1;j<=nw;j++){
            while(k<nw and (a[k]>>i&1^1)){
                k++;
            }
            if(k<=nw)swap(a[k++],a[j]);
        }
        if(a[m]>>i&1){
            while(a[nw]>>i&1^1)nw--;
        }
    }
    int ans=a[1];
    for(int i=1;i<=nw;i++){
        ans&=a[i];
    }
    printf("%lld\n",ans);
    return 0;
}