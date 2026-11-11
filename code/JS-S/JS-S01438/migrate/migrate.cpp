#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll ch,T,n,d,cnt,ans,lft,rgt,t1,t2,a[2000005],c[2000005];
void solve(){
    ans=0;cnt=0;
    scanf("%lld%lld",&n,&d);
    for(ll i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    if(n<=3){
        printf("0\n");
        return;
    }
    t1=2;t2=3;
    while(t1<=n-2){
        //if(binary_search(a+1,a+n+1,a[t1]-d+1)&&binary_search(a+1,a+n+1,a[t2]+d-1)){c[++cnt]=t1;t1++;t2++;continue;}
        if(a[t2+1]-a[t1-1]>d&&a[t2]-a[t1]<d&&a[t2+1]-a[t2]<=d&&a[t1]-a[t1-1]<=d&&a[t2]-a[t1-1]<=d&&a[t2+1]-a[t1]<=d)c[++cnt]=t1;
        t1++;t2++;
    }
    c[++cnt]=n+1;
    for(ll i=1;i<cnt;i++){
        if(c[i+1]-c[i]==1||c[i]-c[i-1]==1)ans++;
        else{
            lft=rgt=0;
            for(ll j=c[i]-1;j>=c[i-1];j--){
                lft++;
                if(j==1)break;
                if(a[j]-a[j-1]>d)break;
            }
            for(ll j=c[i]+2;j<=c[i+1]+1;j++){
                rgt++;
                if(j==n)break;
                if(a[j+1]-a[j]>d)break;
            }
            ans+=(lft)*(rgt);
        }
    }
    printf("%lld\n",ans);
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%lld%lld",&ch,&T);
    for(ll i=1;i<=T;i++)solve();
    return 0;
}
