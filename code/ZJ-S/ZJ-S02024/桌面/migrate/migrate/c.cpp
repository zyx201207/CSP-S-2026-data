#include<bits/stdc++.h>
using namespace std;
long long c,T,n,d,a[2000010],ans;
int cnt[2000010],Left[2000010],Right[2000010],backLeft[2000010],backRight[2000010];
int solve1(int x){
    int l=1,r=x,mid,ans=x;
    while(l<=r){
        mid=(l+r)/2;
        if(a[x]-a[mid]<=d){
            ans=min(ans,mid);
            r=mid-1;
        }else l=mid+1;
    }
    return ans;
}
int solve2(int x){
    int l=x,r=n,mid,ans=x;
    while(l<=r){
        mid=(l+r)/2;
        if(a[mid]-a[x]<=d){
            ans=max(ans,mid);
            l=mid+1;
        }else r=mid-1;
    }
    return ans;
}
int main(){
    freopen("migrate3.in","r",stdin);
    freopen("c.out","w",stdout);
    scanf("%lld%lld",&c,&T);
    while(T--){
        scanf("%lld%lld",&n,&d);
        for(int i=1;i<=n;i++)
            scanf("%lld",&a[i]);
        for(int i=1;i<=n;i++){
            Left[i]=solve1(i);
            backLeft[Left[i]]=i;
            Right[i]=solve2(i);
            backRight[Right[i]]=i;
        }
        for(int i=1;i<=n;i++)cnt[i]=-1;
        for(int i=1;i<=n;i++)
            if(cnt[i]==-1){
                cnt[i]=0;
                if(Right[i]!=i){
                    int j=Right[i];
                    while(j<=n){
                        cnt[j]=cnt[backRight[j]]+1;
                        if(Right[j]!=j)j=Right[j];
                        else break;
                    }
                }
            }
        // cout<<"# ";
        // for(int i=1;i<=n;i++)cout<<cnt[i]<<" ";
        // cout<<"\n";
        ans=0;
        for(int i=1;i<=n;i++)
            if(i-Left[i]>=2 and backRight[Left[i]+1]<Left[i])
                ans+=1ll*cnt[Left[i]+1];
        printf("%lld\n",ans);
    }    
    return 0;
}
