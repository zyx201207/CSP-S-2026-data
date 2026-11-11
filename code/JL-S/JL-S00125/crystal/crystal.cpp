#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+5;
int n,m,ans,a[N],dis[N];
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    int dis=a[2]-a[1];
    int cnt=0;
    int t=0;
    for(int i=1;i<=n;i++){
        t+=i;
    }
    if(m>=t){
           printf("%lld",n);
           exit(0);
       }
    for(int i=1;i<=n;i++){
        cnt+=i;
        if(cnt>m){
             ans=i;
             break;
        }
        }
    printf("%lld",ans);
    return 0;
}