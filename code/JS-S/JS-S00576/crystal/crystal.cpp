#include <bits/stdc++.h>
using namespace std;
using LL=long long;
const int N=5e5+7;

int n;
LL m;
LL a[N];
LL cst;
int ans,cnt;
int pre;

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d%lld",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+n+1);
    cnt=1;
    cst=0;
    for(int i=2;i<=n;i++){
        cst+=1LL*(a[i]-a[i-1])*cnt;
        cnt++;
        if(cst>m){
            while(cst>m){
                cst=cst-(a[i]-a[pre]);
                pre++;
                cnt--;
            }
        }
        ans=max(ans,cnt);
    }
    printf("%d\n",ans);
    return 0;
}
