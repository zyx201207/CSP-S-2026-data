#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+10;
int C,Q,n;
ll d;
ll x[N];
int h[N],t[N];
ll ans;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%d%d",&C,&Q);
    while(Q--){
        ans=0;
        scanf("%d%lld",&n,&d);
        for(int i=1;i<=n;i++){
            scanf("%lld",&x[i]);
            h[i]=t[i]=i;
        }
        if(11<=C&&C<=12){
            int k=(x[n]-x[1])/(n-1);
            k=d/k;
            if(k==1){
                printf("0\n");
            }
            else {
                printf("%d\n",max(n+1-2*k,0));
            }
        }
        else{
            for(int l=1,r=1;l<=n;l++){
                if(r==n)continue;
                while(x[r]-x[l]<=d&&r<=n){
                    h[r]=l;
                    r++;
                }
                t[l]=r-1;
            }
            int l=1;
            while(l<=n){
                if(t[t[l]-1]>t[l]){
                    ans++;
                }
                if(t[l]==l||t[l]-1<=l){
                    l++;
                }
                else{
                    l=t[l]-1;
                }
            }
            printf("%lld\n",ans);
        }

    }
    return 0;
}
