#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long n,m,a[N],ans,l,r,mid,tmp;
bool lright=0;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(long long i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+1+n);
    l=r=1;
    while(r<=n){
        if(!lright) tmp+=((a[r]-a[r-1])*(r-l));
        if(tmp<=m){
            ans=max(ans,r-l+1);
            lright=0;
            r++;
        }
        else{
            tmp-=(a[r]-a[l]);
            lright=1;
            l++;
        }

    }
    printf("%lld\n",ans);
    return 0;
}
