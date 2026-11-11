#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int maxn=5e5+5;
ll n,m,t;
int a[maxn],b[maxn],c[maxn];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    scanf("%lld %lld",&n,&m);
    for(ll i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(ll i=0;i<n;i++){
        t=0;
        for(int j=1;j<=n-i;j++){
            b[++t]=a[i+j];
            for(int k=1;k<t;k++){
                if(b[k]==b[t]){
                    t=k;
                    break;
                }
            }
        }
        for(int i=1;i<=t;i++){
            c[b[i]]++;
        }
    }
    for(int i=1;i<=m;i++){
        printf("%d",c[i]);
        if(i!=m) printf(" ");
    }
    printf("\n");
    return 0;
}
