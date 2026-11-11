#include<bits/stdc++.h>
using namespace std;
#define N 500005
#define ll long long
ll a[N],b[N];
int p[105];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;ll m,maxx=0,minn=0x3f3f3f3f3f3f3f3f;
    cin>>n>>m;
    bool ts1=1,ts2=1;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        if(a[i]!=i){
            ts1=0;
        }
        maxx=max(maxx,a[i]);
        minn=min(minn,a[i]);
    }
    ll tttmp=a[2]-a[1];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;++i){
        b[i]=b[i-1]+a[i];
        if(i!=1){
            if(a[i]-a[i-1]!=tttmp){
                ts2=0;
            }
        }
    }
    if(n<=20000){
        int ans=1;
        for(int i=2;i<=n;++i){
            int cnt=0;ll m1=m;
            for(int j=i-1;j>=1;--j){
                if(m1>=(a[i]-a[j])){
                    m1-=(a[i]-a[j]);
                    ++cnt;
                }else{
                    break;
                }
            }
            ans=max(ans,cnt+1);
        }
        cout<<ans<<'\n';
        return 0;
    }
    if(ts1){//13-15
        int ans=1;
        for(int i=1;i<=n;++i){
            if(b[i-1]<=m){
                ans=max(ans,i);
            }else{
                break;
            }
        }
        cout<<ans<<'\n';
        return 0;
    }
    if(ts2){//16-18
        ll sum=0;
        int ans=1;
        for(int i=1;i<=n;++i){
            if(sum<=m){
                ans=max(ans,i);
                sum=sum+2*i;
            }else{
                break;
            }
        }
        cout<<ans<<'\n';
        return 0;
    }
    if(maxx<=100){//10-12
        for(int i=1;i<=n;++i){
            ++p[a[i]];
        }
        int ans=p[minn];
        for(int i=minn;i<=maxx;++i){
            int cnt=p[i];ll m1=m;
            for(int j=i-1;j>=minn;--j){
                if(!m1){
                    break;
                }
                if(m1>=(i-j)*p[j]){
                    m1-=(i-j)*p[j];
                    cnt+=p[j];
                }else{
                    m1=0;
                    cnt+=m1;
                    break;
                }
            }
            ans=max(ans,cnt);
        }
        cout<<ans<<'\n';
        return 0;
    }
    int ans=1;
    for(int i=2;i<=n;++i){
        int cnt=0;ll m1=m;
        for(int j=i-1;j>=1;--j){
            if(m1>=(a[i]-a[j])){
                m1-=(a[i]-a[j]);
                ++cnt;
            }else{
                break;
            }
        }
        ans=max(ans,cnt+1);
    }
    cout<<ans<<'\n';
    return 0;
}