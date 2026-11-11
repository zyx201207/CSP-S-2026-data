#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,ans,C;
int a[500010];
int d[500010];
int l = 1,r = 1;
int cost = 0;
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld %lld",&n,&m);
    for(int i = 1;i<=n;i++){
        scanf("%lld",&C);
        a[i] = C;
    }
    sort(a+1,a+1+n);
    for(int i = 2;i<=n;i++){
        r++;
        cost+=(a[i]-a[i-1])*(r-l);
        while(l!=r&&cost>m){
            cost-=a[r]-a[l];
            l++;
        }
        d[i] = r-l+1;
        ans = max(d[i],ans);
//        cout<<"number: "<<i<<" cost:"<<cost<<" value:"<<d[i]<<endl;
    }
    printf("%lld",ans);
    return 0;
}
