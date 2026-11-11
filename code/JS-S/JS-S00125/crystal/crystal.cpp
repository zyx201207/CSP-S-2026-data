#include<bits/stdc++.h>
using namespace std;

long long n,m;
long long a[500001];
long long cost[500001];
long long precost[500001];

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+1+n);
    for(int i=n-1;i>=1;i--){
        if(a[i]!=a[i+1]){
            cost[i]=a[i+1]-a[i];
        }else{
            cost[i]=cost[i+1];
        }
    }
    for(int i=1;i<n;i++){
        precost[i]=precost[i-1]+cost[i];
    }
    long long cost_sum=0;
    long long ans=0;
    long long l=0,r=0;
    int t1,t2;
    for(int i=1;i<n;i++){
        if(cost[i]<=m){
            l=i;r=i;
            cost_sum=0;
            break;
        }
    }
    while(r<n){
        r++;
        if(a[r]==a[r-1]){
            ans++;
            continue;
        }
        cost_sum+=(r-l)*cost[r-1];
        if(cost_sum>m){
            while(l<=r && cost_sum>m){
                cost_sum-=precost[r-1]-precost[l-1];
                l++;
            }
        }
        if(l>r){
            for(int i=r;i<n;i++){
                if(cost[i]<=m){
                    l=i;r=i;
                    cost_sum=cost[i];
                }
            }
        }
        printf("%lld %lld\n",l,r);
        if(ans<r-l+1){
            ans=r-l+1;
        }
    }
    printf("%lld",ans);
    return 0;
}
