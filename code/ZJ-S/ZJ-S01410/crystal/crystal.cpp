#include<bits/stdc++.h>
#define int long long
#define For(i,a,b) for(int i=a;i<=b;i++)
#define Fol(i,a,b) for(int i=b;i>=a;i--)
using namespace std;

const int M=5e5+7;

int n,m,a[M],s[M];

int calc(int st){
    int l=1,r=st,mid,ret=1;
    while(l<=r){
        mid=(l+r)>>1;
        //printf("%lld %lld:(%lld %lld)",st,mid,(a[st]*(st-mid+1)),(s[st]-s[mid-1]));

        if((a[st]*(st-mid+1))-(s[st]-s[mid-1])<=m){
            r=mid-1;
            ret=st-mid+1;
        }else{
            l=mid+1;
        }
    }
    return ret;
}

signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    For(i,1,n){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+n+1);
    int ans=1;
    For(i,1,n){
        s[i]=s[i-1]+a[i];
        //printf("%lld\n",calc(i));
        ans=max(ans,calc(i));
    }
    printf("%lld",ans);
    return 0;
}

/*
froepen
chzx_AT AK NGOI!!!!!
*/
