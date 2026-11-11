#include <bits/stdc++.h>
using namespace std;
int n;
long long m,a[500001],s[500001],l=1,r=1,ans;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d%lld",&n,&m);
    for(int i=1;i<=n;i++)scanf("%lld",a+i);
    sort(a+1,a+n+1,[](int x,int y){return x>y;});
    for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
    // for(int i=1;i<=n;i++)printf("%lld ",a[i]);
    // printf("\n");
    // for(int i=1;i<=n;i++)printf("%lld ",s[i]);
    // printf("\n");
    while(l<=n){
        while(r<n&&(r+1-l)*a[l]-(s[r+1]-s[l])<=m){
            // printf("%lld\n",(r+1-l)*a[l]-(s[r+1]-s[l]));
            r++;
        }
        // printf("%lld %lld\n",l,r);
        if(r>=n){ans=max(ans,n-l+1);break;}
        ans=max(ans,r-l+1);
        l++;
    }
    printf("%lld",ans);
    return 0;
}