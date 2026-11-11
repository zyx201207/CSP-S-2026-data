#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005];
long long sum[500005];//qian zhui he

int isok(int l,int r,int aim){//ba l dao r bian cheng aim shi fei ke xing
    long long need;
    need=(r-l+1)*aim-(sum[r]-sum[l-1]);
    return (need<=m);
}

int main( ){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",a+i);
    }
    sort(a+1,a+1+n);//xiao dao da
    for(int i=1;i<=n;i++){
        sum[i]=a[i]+sum[i-1];
    }
    int ans=-INT_MAX;
    for(int i=1;i<=n;i++){
        int l=1,r=i-1,mid;//l r jun ke shi yong
        while(l<r){
            mid=(l+r)/2;
            if(isok(mid,i-1,a[i])){
                r=mid;
            }else{
                l=mid+1;
            }
        }
        int idx=l;
        ans=max(i-idx+1,ans);
    }
    printf("%d\n",ans);
    return 0;
}
//100