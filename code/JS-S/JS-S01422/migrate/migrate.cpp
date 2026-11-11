#include <bits/stdc++.h>
using namespace std;
const int MAXN=2e6+5;
long long x[MAXN], lb[MAXN], rb[MAXN], tp0[MAXN], tp1[MAXN], d, ans;
int c, t, n;
int bound1(long long value){
    int l=1, r=n, mid=0;
    while(l<r){
        mid=(l+r)/2;
        if(x[mid]>=value){r=mid;}
        else{
            l=mid+1;
        }
    }
    return l;
}
int bound2(long long value){
    int l=1, r=n, mid=0;
    while(l<r){
        mid=(l+r+1)>>1;
        if(x[mid]<=value){
            l=mid;
        }else{r=mid-1;}
    }
    return l;
}
int main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    scanf("%d%d", &c, &t);
    while(t--){
        ans=0;
        scanf("%d%lld", &n, &d);
        for(int i=1; i<=n; i++){
            scanf("%lld", &x[i]);
            tp0[i]=i; tp1[i]=i;
        }
        for(int i=1; i<=n; i++){
            lb[i]=bound1(x[i]-d);
            rb[i]=bound2(x[i]+d);
        }
        tp0[n-1]=n; tp1[2]=1;
        for(int i=n-2; i>=1; i--){
            if(x[i+1]-x[i]<=d){
                if(x[i+2]-x[i]>d){
                    tp0[i]=tp0[i+1];
                }
            }
        }
        for(int i=2; i<=n; i++){
            if(x[i+1]-x[i]<=d){
                if(x[i+1]-x[i-1]>d){
                    tp1[i+1]=tp1[i];
                }
            }
        }
        for(int i=2; i<n-1; i++){
            if(x[i+1]-x[i]<=d){
                ans+=1ll*(lb[i+2]-tp1[i+1])*(tp0[i]-rb[i-1]);
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}
