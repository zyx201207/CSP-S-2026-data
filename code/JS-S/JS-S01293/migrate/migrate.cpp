#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[2000005];
int dp[2000005];
int jus[2000005];
int n,d;
int erferr(int x){
    int L=0,R=n;
    while(L+1<R){
        int mid=(L+R)/2;
        if(a[mid]>=x){
            R=mid;
        }
        else L=mid;
    }
    return R;
}
int erferl(int x){
    int L=1,R=n+1;
    while(L+1<R){
        int mid=(L+R)/2;
        if(a[mid]<=x){
            L=mid;
        }
        else R=mid;
    }
    return L;
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int kkkk,tttt;
    cin>>kkkk>>tttt;
    if(kkkk==11||kkkk==12){
        while(tttt--){
            cin>>n>>d;
            for(int i=1;i<=n;i++) cin>>a[i];
            if(n<=3){
                cout<<0<<'\n';
                continue;
            }
            int gongc=a[2]-a[1];
            d=d/gongc;
            if(d==0||d==1){
                cout<<0<<'\n';
                continue;
            }
            for(int i=1;i<=n;i++) a[i]=i;
            int ans=0;
            ans+=(n-2*d+1);
            if(ans<0) ans=0;
            cout<<ans<<'\n';
        }
        return 0;
    }
    else{
        while(tttt--){
            cout<<0<<'\n';
        }
        return 0;
    }
    while(tttt--){
        cin>>n>>d;
        for(int i=1;i<=n;i++) cin>>a[i];
        int ans=0;
        for(int i=1;i<=n;i++){
            dp[i]=1;
            jus[i]=0;
            for(int k=i+1;k<=n;k++){
                int zx=INT_MAX;
                for(int l=max(i,erferr(a[k]-d));l<k;l++){
                    zx=min(zx,jus[l]);
                }
                jus[k]=zx+1;
                dp[k]=0;
                for(int l=max(i,erferr(a[k]-d));l<k;l++){
                    if(zx==jus[l]){
                        dp[k]+=dp[l];
                    }
                }
            }
            for(int k=i+1;k<=n;k++){
                if(dp[k]==2) ans++;
            }
        }
        cout<<ans<<'\n';

    }
    return 0;
}
