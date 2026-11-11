#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll crsss[500010];
ll ans=1,tempansss=1;
//ll ave=0;
int main(){
    ll n,m,tempmmm;
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld %lld",&n,&m);
    for(ll i=0;i<n;i++){
        scanf("%lld",&crsss[i]);
        //ave+=crsss[i];
    }
    //ave=ave/n;
    sort(crsss,crsss+n);
    for(ll i=n-1;i>0;i--){
        tempmmm=m;
        tempansss=1;
        for(ll j=i-1;j>=0;j--){
            if(tempmmm<crsss[i]-crsss[j])break;
            tempmmm-=crsss[i]-crsss[j];
            tempansss++;
        }
        ans=max(ans,tempansss);
    }
    printf("%lld",ans);
    //system("fc crystal.out crystal1.ans");
    return 0;
}