#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,a[2000005],dp[2000005],an[2000005],fr[2000005],nx[2000005],nb[2000005],ans,po;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    for(long long j=0;j<t;j++){
        cin>>n>>d;
        for(long long k=0;k<n;k++){
            cin>>a[k];
        }
        if(n==1){
            cout<<0;continue;
        }
        for(long long k=0;k<n;k++){
            nx[k]=lower_bound(a,a+n,a[k]-d)-a;
        }
        ans=0;
        if(c<=10||c>=13){
            for(long long k=0;k<n;k++){
                dp[k]=1,an[k]=0;fr[k+1]=1;po=k;
                for(long long l=k+1;l<n;l++){
                    long long v=max(nx[l],k),w;
                    an[l]=an[v]+1;
                    if(an[l]!=an[l-1]){
                        po=l;
                    }
                    w=po;
                    dp[l]=fr[w]-fr[v];fr[l+1]=fr[l]+dp[l];
                    if(dp[l]==2){
                        ans++;
                    }
                    if(l==n-1||a[k+1]-a[k]>d){
                        break;
                    }
                }
                for(long long l=0;l<=n;l++){
                    dp[l]=an[l]=fr[l]=nb[l]=0;
                }
            }
            cout<<ans<<'\n';
        }else if(c>=11&&c<=12){
            if((a[1]-a[0])*2>d){
                cout<<0<<'\n';
            }else{
                long long vk=d/(a[1]-a[0])*2-1;
                for(long long k=0;k<n;k++){
                    ans+=min(1LL,(n-k-1)/vk);
                }
                cout<<ans<<'\n';
            }
        }
    }
}
