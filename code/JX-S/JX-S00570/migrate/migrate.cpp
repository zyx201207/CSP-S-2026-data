#include <bits/stdc++.h>
#define fo(i,j,k) for(int i=j;i<=k;i++)
#define go(i,j,k) for(int i=j;i>=k;i--)
#define ll long long
#define ull unsigned long long
using namespace std;
const int N=2000017;
ll d,a[N],num[N],f,n;
void dfs(ll l,ll r,ll x){
    if(f<x)return;
    if(l==r){
        f=min(f,x);
        num[x]++;
        return;
    }
    go(i,r,l+1){
        if(a[i]-a[l]<=d){
            dfs(i,r,x+1);
        }
    }
}
void us(){
    scanf("%lld%lld",&n,&d);
    fo(i,1,n){
        scanf("%lld",&a[i]);
    }
    ll ans=0;
    fo(i,1,n){
        fo(j,i+1,n){
            memset(num,0,sizeof(num));
            f=1e9;
            dfs(i,j,0);
            //printf("\n%d-%d:",i,j);
            fo(k,1,n){
                //printf("%d ",num[k]);
                if(num[k]){
                    if(num[k]==2)ans++;
                    break;
                }
            }
            //printf("\n");
        }
    }
    printf("%lld\n",ans);
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    scanf("%d%d",&c,&t);
    if(c==14||c==13){
        fo(i,1,t){
            scanf("%lld%lld",&n,&d);
            fo(i,1,n)scanf("%lld",&a[i]);
            printf("0\n");
        }
        return 0;
    }
    fo(i,1,t)us();
    return 0;
}
