#include <bits/stdc++.h>
using namespace std;
int n;
long long m;
long long a[500010],s[500010];
bool calc(int x,int y){
    long long ret=s[y]-s[x-1];
    ret-=1LL*(y-x+1)*(abs(a[y]-a[n]));
    return ret<=m;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d%lld",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
        s[i]=s[i-1]+abs(a[i]-a[n]);
    int ans=0;
    for(int i=1;i<=n;i++){
        int l=0,r=i+1;
        while(l+1<r){
            int M=(l+r)/2;
            if(calc(M,i))
                r=M;
            else
                l=M;
        }
        if(r==i+1)
            continue;
        ans=max(ans,i-r+1);
    }
    printf("%d\n",ans);
    return 0;
}
